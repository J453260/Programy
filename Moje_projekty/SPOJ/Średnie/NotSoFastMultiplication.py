import sys

# Zniesienie limitu długości konwersji int dla bardzo dużych liczb
sys.set_int_max_str_digits(0)

def main():
    # Wczytanie wszystkich danych z wejścia
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    idx = 1
    
    for _ in range(n):
        l1 = int(input_data[idx])
        l2 = int(input_data[idx + 1])
        print(l1 * l2)
        idx += 2

if __name__ == "__main__":
    main()
