#!/bin/bash

# Colores para una mejor visualización
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Nombre del programa
PUSH_SWAP=./push_swap
CHECKER=./checker_linux

# Función para imprimir mensajes con formato
print_header() {
    echo -e "\n${BLUE}=== $1 ===${NC}\n"
}

print_test() {
    echo -e "${YELLOW}Test: $1${NC}"
}

print_success() {
    echo -e "${GREEN}✓ $1${NC}"
}

print_error() {
    echo -e "${RED}✗ $1${NC}"
}

# Función para generar números aleatorios sin duplicados
generate_random_numbers() {
    local count=$1
    seq 1 1000 | shuf -n $count | tr '\n' ' '
}

# Verificar si el programa existe
if [ ! -f "$PUSH_SWAP" ]; then
    print_error "El programa $PUSH_SWAP no existe. Compila tu proyecto primero."
    exit 1
fi

# Pruebas básicas
print_header "PRUEBAS BÁSICAS"

# Prueba sin argumentos
print_test "Sin argumentos"
output=$($PUSH_SWAP)
if [ -z "$output" ]; then
    print_success "OK - No se imprimió nada"
else
    print_error "ERROR - Se esperaba que no imprimiera nada"
fi

# Prueba con un solo número
print_test "Un solo número (42)"
output=$($PUSH_SWAP 42)
if [ -z "$output" ]; then
    print_success "OK - No se imprimió nada"
else
    print_error "ERROR - Se esperaba que no imprimiera nada"
fi

# Prueba con números ya ordenados
print_test "Números ya ordenados (1 2 3 4 5)"
output=$($PUSH_SWAP 1 2 3 4 5)
if [ -z "$output" ]; then
    print_success "OK - No se imprimió nada"
else
    print_error "ERROR - Se esperaba que no imprimiera nada"
fi

# Pruebas de error
print_header "PRUEBAS DE ERROR"

# Argumentos no numéricos
print_test "Argumento no numérico (abc)"
output=$($PUSH_SWAP abc 2>&1)
if [ "$output" = "Error" ]; then
    print_success "OK - Se imprimió 'Error'"
else
    print_error "ERROR - Se esperaba 'Error', pero se obtuvo: $output"
fi

# Duplicados
print_test "Duplicados (1 2 3 3 4)"
output=$($PUSH_SWAP 1 2 3 3 4 2>&1)
if [ "$output" = "Error" ]; then
    print_success "OK - Se imprimió 'Error'"
else
    print_error "ERROR - Se esperaba 'Error', pero se obtuvo: $output"
fi

# Desbordamiento INT
print_test "Desbordamiento INT (2147483648)"
output=$($PUSH_SWAP 2147483648 2>&1)
if [ "$output" = "Error" ]; then
    print_success "OK - Se imprimió 'Error'"
else
    print_error "ERROR - Se esperaba 'Error', pero se obtuvo: $output"
fi

# Pruebas de funcionamiento
print_header "PRUEBAS DE FUNCIONAMIENTO"

# 3 números
print_test "3 números (3 1 2)"
output=$($PUSH_SWAP 3 1 2)
operations=$(echo "$output" | wc -l)
echo "Número de operaciones: $operations"
if [ -f "$CHECKER" ]; then
    result=$(echo "$output" | $CHECKER 3 1 2)
    if [ "$result" = "OK" ]; then
        print_success "OK - El checker dice que la ordenación es correcta"
    else
        print_error "ERROR - El checker dice que la ordenación es incorrecta"
    fi
else
    echo "El checker no está disponible para verificar la ordenación."
fi

# 5 números
print_test "5 números (5 1 4 2 3)"
output=$($PUSH_SWAP 5 1 4 2 3)
operations=$(echo "$output" | wc -l)
echo "Número de operaciones: $operations"
if [ -f "$CHECKER" ]; then
    result=$(echo "$output" | $CHECKER 5 1 4 2 3)
    if [ "$result" = "OK" ]; then
        print_success "OK - El checker dice que la ordenación es correcta"
    else
        print_error "ERROR - El checker dice que la ordenación es incorrecta"
    fi
else
    echo "El checker no está disponible para verificar la ordenación."
fi

# Pruebas de rendimiento
print_header "PRUEBAS DE RENDIMIENTO"

# 100 números aleatorios (5 pruebas)
print_test "100 números aleatorios (5 pruebas)"
total_ops=0
max_ops=0
min_ops=999999

for ((i=1; i<=5; i++)); do
    numbers=$(generate_random_numbers 100)
    output=$($PUSH_SWAP $numbers)
    operations=$(echo "$output" | wc -l)
    total_ops=$((total_ops + operations))
    
    if [ "$operations" -gt "$max_ops" ]; then
        max_ops=$operations
    fi
    
    if [ "$operations" -lt "$min_ops" ]; then
        min_ops=$operations
    fi
    
    echo "Prueba $i: $operations operaciones"
    
    if [ -f "$CHECKER" ]; then
        result=$(echo "$output" | $CHECKER $numbers)
        if [ "$result" = "OK" ]; then
            print_success "OK - El checker dice que la ordenación es correcta"
        else
            print_error "ERROR - El checker dice que la ordenación es incorrecta"
        fi
    fi
done

avg_ops=$((total_ops / 5))
echo "Promedio: $avg_ops operaciones (mín: $min_ops, máx: $max_ops)"

if [ "$max_ops" -le 700 ]; then
    print_success "EXCELENTE - Operaciones <= 700 (cumple el requisito mínimo)"
elif [ "$max_ops" -le 900 ]; then
    print_success "BUENO - Operaciones <= 900"
else
    print_error "A MEJORAR - Operaciones > 900 (no cumple el requisito mínimo de <= 700)"
fi

# 500 números aleatorios (3 pruebas)
print_test "500 números aleatorios (3 pruebas)"
total_ops=0
max_ops=0
min_ops=999999

for ((i=1; i<=3; i++)); do
    numbers=$(generate_random_numbers 500)
    output=$($PUSH_SWAP $numbers)
    operations=$(echo "$output" | wc -l)
    total_ops=$((total_ops + operations))
    
    if [ "$operations" -gt "$max_ops" ]; then
        max_ops=$operations
    fi
    
    if [ "$operations" -lt "$min_ops" ]; then
        min_ops=$operations
    fi
    
    echo "Prueba $i: $operations operaciones"
    
    if [ -f "$CHECKER" ]; then
        result=$(echo "$output" | $CHECKER $numbers)
        if [ "$result" = "OK" ]; then
            print_success "OK - El checker dice que la ordenación es correcta"
        else
            print_error "ERROR - El checker dice que la ordenación es incorrecta"
        fi
    fi
done

avg_ops=$((total_ops / 3))
echo "Promedio: $avg_ops operaciones (mín: $min_ops, máx: $max_ops)"

if [ "$max_ops" -le 5500 ]; then
    print_success "EXCELENTE - Operaciones <= 5500 (cumple el requisito para los bonus)"
elif [ "$max_ops" -le 7000 ]; then
    print_success "BUENO - Operaciones <= 7000"
else
    print_error "A MEJORAR - Operaciones > 7000 (no cumple el requisito bonus de <= 5500)"
fi

# Resumen final
print_header "RESUMEN"
echo -e "${CYAN}Este script ha ejecutado varias pruebas en tu implementación de push_swap.${NC}"
echo -e "${CYAN}Asegúrate de revisar los mensajes de error y mejorar tu código si es necesario.${NC}"
echo -e "${CYAN}También verifica la norminette y asegúrate de que no haya errores ni fugas de memoria.${NC}"
