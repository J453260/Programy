/**
 * InterfejsRobota - interfejs, za pomocą którego można sterować ruchem robota.
 */
public interface InterfejsRobota {
    /**
     * Zlecenie wykonania ruchu robota w danym kierunku.
     * Metoda zwraca informację o kratce na jakiej znajduje się robot.
     * Jeśli pozycja (kratka) nie uległa zmianie, zlecony ruch nie mógł
     * zostać wykonany, bo robot natrafił na ścianę.
     *
     * @param kierunek zlecony kierunek ruchu robota
     * @return KolorowaKratka - informacje o kratce na jakiej znajduje się robot
     */
    public KolorowaKratka wykonajKrok( Kierunek kierunek );
}