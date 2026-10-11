#!/usr/bin/env python3
"""Run with: python3 tests/regression.py [--sanitize]. Requires GCC on Linux."""
import argparse
import os
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--sanitize", action="store_true")
args = parser.parse_args()
FLAGS = ["-Wall", "-Wextra", "-Werror", "-g"]
if args.sanitize:
    FLAGS += ["-fsanitize=address,undefined", "-fno-omit-frame-pointer"]

CALLOC = r'''
#include "libft.h"
#include <assert.h>
#include <limits.h>
int main(void) {
    assert(ft_calloc(ULONG_MAX / 2 + 1, 2) == NULL);
    unsigned char *p = ft_calloc(8, 1);
    assert(p);
    for (int i = 0; i < 8; i++) assert(p[i] == 0);
    free(p);
    free(ft_calloc(0, 8));
    return 0;
}
'''
PRINTF = r'''
#include "ft_printf.h"
#include <assert.h>
int main(void) {
    assert(ft_printf("%s %d %u %x %%\n", "DAM", -42, 42u, 255u) == 16);
    assert(ft_printf("%") == 0);
    assert(ft_printf("end%") == 3);
    return 0;
}
'''
GNL = r'''
#include "get_next_line.h"
#include <assert.h>
static int calls, live, fail_at;
void *__real_malloc(size_t n);
void __real_free(void *p);
void *__wrap_malloc(size_t n) {
    if (++calls == fail_at) return NULL;
    void *p = __real_malloc(n);
    if (p) live++;
    return p;
}
void __wrap_free(void *p) {
    if (p) live--;
    __real_free(p);
}
int main(int argc, char **argv) {
    assert(argc == 2);
    fail_at = atoi(argv[1]);
    char *line;
    while ((line = get_next_line(STDIN_FILENO))) {
        if (!fail_at) fputs(line, stdout);
        __wrap_free(line);
    }
    assert(get_next_line(-1) == NULL);
    assert(live == 0);
    return 0;
}
'''

def run(command, **kwargs):
    return subprocess.run(command, check=True, timeout=30, **kwargs)

with tempfile.TemporaryDirectory(prefix="42-regression-") as temp:
    temp = Path(temp)
    for source in sorted(ROOT.glob("**/libft/ft_calloc.c")):
        test = temp / "calloc.c"
        test.write_text(CALLOC)
        exe = temp / "calloc"
        run(["gcc", *FLAGS, "-I" + str(source.parent), str(test), str(source), "-o", str(exe)])
        run([str(exe)])
        print("PASS calloc:", source.relative_to(ROOT))
    for source in sorted(ROOT.glob("**/ft_printf/ft_printf.c")):
        test = temp / "printf.c"
        test.write_text(PRINTF)
        exe = temp / "printf"
        sources = sorted(source.parent.glob("*.c"))
        run(["gcc", *FLAGS, "-I" + str(source.parent), str(test), *map(str, sources), "-o", str(exe)])
        result = run([str(exe)], capture_output=True, text=True)
        assert result.stdout == "DAM -42 42 ff %\nend"
        print("PASS printf:", source.relative_to(ROOT))
    test = temp / "gnl.c"
    test.write_text(GNL)
    exe = temp / "gnl"
    folder = ROOT / "get_next_line"
    run(["gcc", *FLAGS, "-D", "BUFFER_SIZE=42", "-I" + str(folder), str(test),
         str(folder / "get_next_line.c"), str(folder / "get_next_line_utils.c"),
         "-Wl,--wrap=malloc", "-Wl,--wrap=free", "-o", str(exe)])
    for content in ["", "uno\ndos\n", "uno\n\ndos", "x" * 10000 + "\nfin"]:
        result = run([str(exe), "0"], input=content, text=True, capture_output=True)
        assert result.stdout == content
    # Force every allocation in the short fixture to fail, one at a time.
    for allocation in range(1, 13):
        run([str(exe), str(allocation)], input="uno\ndos\nfin", text=True, capture_output=True)
    print("PASS get_next_line: normal input and 12 allocation failure positions")
