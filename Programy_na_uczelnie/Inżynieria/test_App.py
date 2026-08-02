from App import dodawanie, odejmowanie

def test_dodawanie():
    assert dodawanie(2, 3) == 5
    assert dodawanie(-2, -3) == -5

def test_odejmowanie_podstawowe():
    assert odejmowanie(10, 4) == 6
    assert odejmowanie(3, 5) == -2
