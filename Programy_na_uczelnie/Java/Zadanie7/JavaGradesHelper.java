import java.util.*;
import java.io.*;

public class JavaGradesHelper implements GradesHelper{

    private Map<Integer, String> imiona = new HashMap<>();
    private Map<Integer, String> nazwiska = new HashMap<>();
    private Map<String, double[]> oceny = new HashMap<>();

    @Override
    public void loadStudents(String file){
        try(BufferedReader studenciID = new BufferedReader(new FileReader(file))) {
            String linia;
            while ((linia = studenciID.readLine()) != null) {
                String[] skladowe = linia.split(";");

                if (skladowe.length < 3) {
                    continue;
                    //jeżeli niepoprawny format to idę do następnej iteracji
                }

                int ID = Integer.parseInt(skladowe[0]);
                String imie = skladowe[1];
                String nazwisko = skladowe[2];

                imiona.put(ID, imie);
                nazwiska.put(ID, nazwisko);
            }
        }catch (IOException e) {
        }
    }

    @Override
    public void loadScoring(String file) throws RangeConflictException, MarkConflictException{

        try(BufferedReader zasadyOceniania = new BufferedReader(new FileReader(file))) {
            String linia;
            while ((linia = zasadyOceniania.readLine()) != null) {
                String[] skladowe = linia.split(";");
                if (skladowe.length < 3) continue;


                String ocena = skladowe[0];
                double dolny = Double.parseDouble(skladowe[1]);
                double gorny = Double.parseDouble(skladowe[2]);

                if (oceny.containsKey(ocena)) {
                    double[] istniejacy = oceny.get(ocena);
                    if (istniejacy[0] != dolny || istniejacy[1] != gorny) {
                        throw new MarkConflictException(ocena);
                    }
                    continue;
                }

                for (double[] zakres : oceny.values()) {
                    boolean nachodza =
                            dolny <= zakres[1] && gorny >= zakres[0];

                    if (nachodza) {
                        throw new RangeConflictException();
                    }
                }

                oceny.put(ocena, new double[]{dolny, gorny});
            }

            //zasadyOceniania.close();
        }catch (IOException e) {
        }

    }

    @Override
    public Map<Integer, String> generateGrades(String data) throws AssessmentImpossible{

        Map<Integer, String> ocenyKoncowe = new HashMap<>();

        try(BufferedReader noty = new BufferedReader(new FileReader(data))) {
            String linia;
            while ((linia = noty.readLine()) != null) {
                String[] skladowe = linia.split(";");

                if (skladowe.length < 3) {
                    continue;
                    //jeżeli niepoprawny format to idę do następnej iteracji
                }

                String imieSkl = skladowe[0];
                String nazwiskoSkl = skladowe[1];

                boolean znaleziony = false;
                int ID = -1;

                for (Map.Entry<Integer, String> idst : imiona.entrySet()) {
                    if (idst.getValue().equals(imieSkl) && nazwiska.get(idst.getKey()).equals(nazwiskoSkl)) {

                        if (znaleziony) {
                            throw new AssessmentImpossible(imieSkl, nazwiskoSkl);
                            //wyjątek gdy jest więcej niż 1 student o takim samym imieniu i nazwisku
                        }

                        znaleziony = true;
                        ID = idst.getKey();
                    }
                }

                if (!znaleziony) {
                    throw new AssessmentImpossible(imieSkl, nazwiskoSkl);
                    //student nie istnieje
                }

                double suma = 0;
                for (int i = 2; i < skladowe.length; i++) {
                    suma += Double.parseDouble(skladowe[i]);
                }

                double srednia = suma / (skladowe.length - 2);

                String ocena = null;
                for (Map.Entry<String, double[]> e : oceny.entrySet()) {
                    double min = e.getValue()[0];
                    double max = e.getValue()[1];

                    if (srednia >= min && srednia <= max) {
                        ocena = e.getKey();
                        break;
                    }
                }

                if (ocena == null) {
                    throw new AssessmentImpossible(imieSkl, nazwiskoSkl);
                }

                ocenyKoncowe.put(ID, ocena);
            }

        }catch (IOException e) {
        }

        return ocenyKoncowe;
    }
}
