#!/usr/bin/env python3
"""Validate push_swap operations against a separate stack simulator."""
from itertools import permutations
from pathlib import Path
import random
import subprocess

EXE = Path(__file__).resolve().parents[1] / "push_swap"
OPS = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"}


def run_program(args):
    return subprocess.run(
        [str(EXE), *args], text=True, capture_output=True, timeout=20
    )


def apply(name, a, b):
    if name in ("sa", "ss") and len(a) >= 2:
        a[0], a[1] = a[1], a[0]
    if name in ("sb", "ss") and len(b) >= 2:
        b[0], b[1] = b[1], b[0]
    if name == "pa" and b:
        a.insert(0, b.pop(0))
    if name == "pb" and a:
        b.insert(0, a.pop(0))
    if name in ("ra", "rr") and len(a) >= 2:
        a.append(a.pop(0))
    if name in ("rb", "rr") and len(b) >= 2:
        b.append(b.pop(0))
    if name in ("rra", "rrr") and len(a) >= 2:
        a.insert(0, a.pop())
    if name in ("rrb", "rrr") and len(b) >= 2:
        b.insert(0, b.pop())


def assert_sorted(values, one_string=False):
    args = [" ".join(map(str, values))] if one_string else list(map(str, values))
    result = run_program(args)
    assert result.returncode == 0, (values[:12], result.stderr)
    a, b = list(values), []
    for op in result.stdout.splitlines():
        assert op in OPS, (values[:12], op)
        apply(op, a, b)
    assert a == sorted(values) and not b, (values[:12], a[:12], b[:12])
    if values == sorted(values):
        assert not result.stdout, "Sorted input must not generate operations"
    return len(result.stdout.splitlines())


def main():
    assert EXE.is_file(), "Run: make -C push_swap_final"
    assert run_program([]).returncode == 0
    assert not run_program([]).stdout
    cases = 0
    max_ops = 0
    for size in range(1, 6):
        for values in permutations(range(size)):
            max_ops = max(max_ops, assert_sorted(values))
            cases += 1
    for values in (
        [-2147483648, 2147483647, 0, -1, 1],
        [99, 1, -99, 0, 5, -10],
        [42],
    ):
        max_ops = max(max_ops, assert_sorted(values, one_string=True))
        cases += 1
    rng = random.Random(42)
    for size in (10, 50, 100, 500):
        for _ in range(5 if size < 500 else 2):
            values = rng.sample(range(-1000000, 1000000), size)
            max_ops = max(max_ops, assert_sorted(values))
            cases += 1
    for invalid in (
        ["1", "1"], ["x"], [""], ["--1"], ["+"], ["1a"],
        ["2147483648"], ["-2147483649"], ["99999999999999999999999999999"],
        ["-99999999999999999999999999999"], ["1", "2", "1"],
    ):
        result = run_program(invalid)
        assert result.returncode != 0, ("Accepted invalid input", invalid)
        assert "Error" in result.stderr, invalid
    print(f"PASS: {cases} valid cases, 11 invalid cases; max operations {max_ops}")


if __name__ == "__main__":
    main()
