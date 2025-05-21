import random
import subprocess
import sys
from collections import deque

# Constantes
PUSH_SWAP_EXEC = "./push_swap_final/push_swap"
MIN_VAL = -100000
MAX_VAL = 100000

# --- Funciones de Operaciones del Checker ---
def _sa(stack_a):
    if len(stack_a) >= 2:
        stack_a[0], stack_a[1] = stack_a[1], stack_a[0]

def _sb(stack_b):
    if len(stack_b) >= 2:
        stack_b[0], stack_b[1] = stack_b[1], stack_b[0]

def _ss(stack_a, stack_b):
    _sa(stack_a)
    _sb(stack_b)

def _pa(stack_a, stack_b):
    if stack_b:
        stack_a.appendleft(stack_b.popleft())

def _pb(stack_a, stack_b):
    if stack_a:
        stack_b.appendleft(stack_a.popleft())

def _ra(stack_a):
    if len(stack_a) >= 2:
        stack_a.append(stack_a.popleft())

def _rb(stack_b):
    if len(stack_b) >= 2:
        stack_b.append(stack_b.popleft())

def _rr(stack_a, stack_b):
    _ra(stack_a)
    _rb(stack_b)

def _rra(stack_a):
    if len(stack_a) >= 2:
        stack_a.appendleft(stack_a.pop())

def _rrb(stack_b):
    if len(stack_b) >= 2:
        stack_b.appendleft(stack_b.pop())

def _rrr(stack_a, stack_b):
    _rra(stack_a)
    _rrb(stack_b)

OPERATIONS_MAP = {
    "sa": _sa, "sb": _sb, "ss": _ss,
    "pa": _pa, "pb": _pb,
    "ra": _ra, "rb": _rb, "rr": _rr,
    "rra": _rra, "rrb": _rrb, "rrr": _rrr,
}

def generate_random_unique_numbers(n, min_val=MIN_VAL, max_val=MAX_VAL):
    """Genera una lista de N enteros únicos y aleatorios."""
    if n > (max_val - min_val + 1):
        raise ValueError("No se pueden generar más números únicos que el rango disponible.")
    return random.sample(range(min_val, max_val + 1), n)

def run_push_swap(numbers):
    """Ejecuta push_swap con los números dados y devuelve la lista de operaciones."""
    args = [str(num) for num in numbers]
    try:
        process = subprocess.run([PUSH_SWAP_EXEC] + args, capture_output=True, text=True, check=True)
        operations = process.stdout.strip().split('\n')
        # Filtrar líneas vacías si las hubiera (aunque no debería si push_swap es correcto)
        return [op for op in operations if op]
    except FileNotFoundError:
        print(f"Error: El ejecutable '{PUSH_SWAP_EXEC}' no fue encontrado.", file=sys.stderr)
        return None
    except subprocess.CalledProcessError as e:
        print(f"Error al ejecutar push_swap: {e}", file=sys.stderr)
        print(f"Stderr: {e.stderr}", file=sys.stderr)
        return None
    except Exception as e:
        print(f"Una excepción inesperada ocurrió al correr push_swap: {e}", file=sys.stderr)
        return None


def apply_operations(initial_a_list, operations):
    """
    Simula los stacks y aplica las operaciones.
    Devuelve True si a está ordenado y b vacío, sino False.
    """
    stack_a = deque(initial_a_list)
    stack_b = deque()

    for op_str in operations:
        op_func = OPERATIONS_MAP.get(op_str)
        if not op_func:
            print(f"Error: Operación desconocida '{op_str}'", file=sys.stderr)
            return False # Operación inválida

        # Las funciones de operación que toman ambos stacks necesitan pasárselos
        if op_str in ["ss", "rr", "rrr"]:
            op_func(stack_a, stack_b)
        elif op_str in ["pa"]:
            op_func(stack_a, stack_b) # pa(a,b)
        elif op_str in ["pb"]:
            op_func(stack_a, stack_b) # pb(a,b)
        elif op_str.endswith('a'): # sa, ra, rra
            op_func(stack_a)
        elif op_str.endswith('b'): # sb, rb, rrb
            op_func(stack_b)
        else:
            # Esto no debería ocurrir si OPERATIONS_MAP es completo
            print(f"Error: Lógica de despacho de operación fallida para '{op_str}'", file=sys.stderr)
            return False
            
    # Verificar si stack_a está ordenado y stack_b vacío
    is_sorted = all(stack_a[i] <= stack_a[i+1] for i in range(len(stack_a)-1))
    return is_sorted and not stack_b


def run_test_case(n_numbers):
    """Ejecuta un caso de prueba para N números."""
    print(f"--- Test para {n_numbers} números ---")
    
    try:
        numbers = generate_random_unique_numbers(n_numbers)
    except ValueError as e:
        print(f"Error generando números: {e}", file=sys.stderr)
        print("Resultado: KO (Generación de números)")
        return

    # print(f"Números generados (primeros 10): {numbers[:10]}") # Descomentar para debug

    operations = run_push_swap(numbers)

    if operations is None:
        print("Resultado: KO (Ejecución de push_swap fallida)")
        return

    num_operations = len(operations)
    # print(f"Operaciones (primeras 10): {operations[:10]}") # Descomentar para debug


    is_correctly_sorted = apply_operations(list(numbers), operations) # Pasamos una copia de numbers

    result_str = "OK" if is_correctly_sorted else "KO"
    
    print(f"Test para {n_numbers} números: {num_operations} operaciones. Resultado: {result_str}")
    if not is_correctly_sorted:
        # Podríamos imprimir más detalles si es KO, como el estado final de los stacks.
        # temp_a = deque(numbers)
        # temp_b = deque()
        # ... (re-aplicar operaciones para mostrar estado final)
        pass

def compile_push_swap():
    """Intenta compilar push_swap usando make."""
    print("Intentando compilar push_swap...")
    try:
        # Asumimos que el Makefile está en el directorio push_swap_final
        # y que compila el ejecutable en su raíz (./push_swap_final/push_swap)
        make_process = subprocess.run(["make", "-C", "push_swap_final"], 
                                      check=True, capture_output=True, text=True)
        print("push_swap compilado exitosamente.")
        # print(make_process.stdout) # Descomentar para ver salida de make
        return True
    except subprocess.CalledProcessError as e:
        print(f"Error al compilar push_swap con make: {e}", file=sys.stderr)
        print(f"Stderr: {e.stderr}", file=sys.stderr)
        return False
    except FileNotFoundError:
        print("Error: Comando 'make' no encontrado. Asegúrate de que make esté instalado y en el PATH.", file=sys.stderr)
        print("O compila manualmente 'push_swap' antes de ejecutar el tester.", file=sys.stderr)
        return False

def main():
    # Primero, compilar push_swap
    if not compile_push_swap():
        print("No se pudo compilar push_swap. Abortando tests.", file=sys.stderr)
        return

    # Ejecutar pruebas
    run_test_case(5) # Un caso pequeño para probar rápidamente
    run_test_case(100)
    run_test_case(500)

if __name__ == "__main__":
    main()
