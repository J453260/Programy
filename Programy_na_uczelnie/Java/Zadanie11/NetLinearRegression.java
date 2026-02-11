import java.io.*;
import java.net.Socket;
import java.util.*;

public class NetLinearRegression implements NetConnection{
    public HashMap<Double, Double> paryPunktow = new HashMap<>();

    private static double parserZmieniacz(String s) {
        s = s.trim().replace(',', '.');
        return Double.parseDouble(s);
    }

    public HashMap<Double, Double> metodaNajmniejszychKwadratow(){
        HashMap<Double, Double> wyniki = new HashMap<>();
        /**
         * wzory:
         * a = (NΣ(xy) - ΣxΣy) / (NΣ(x^2) - (Σx)^2)
         * b = Σy - aΣx / N
         * N to liczba punktów
         */
        int N = paryPunktow.size();
        double a, b;
        double c=0, d=0, e=0, f=0;
        /**
         * c = NΣ(xy)
         * d = suma x
         * e = suma y
         * f = NΣ(x^2)
         */

        for(HashMap.Entry<Double, Double> para : paryPunktow.entrySet()){
            double x = para.getKey();
            double y = para.getValue();

            c += x*y;
            d += x;
            e += y;
            f += x*x;
        }

        /**
         * wzory:
         * a = (NΣ(xy) - ΣxΣy) / (NΣ(x^2) - (Σx)^2)
         * b = Σy - aΣx / N
         * N to liczba punktów
         */

        a = (N*c - d*e) / (N*f - d*d);
        b = (e - a*d) / N;

        wyniki.put(a, b);
        return wyniki;
    }

    @Override
    public void connectExecuteClose(String host, int port) {
        try (
                Socket socket = new Socket(host, port);
                BufferedReader odbior = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter wysylka = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()), true)
        ) {
            String linia;
            while ((linia = odbior.readLine()) != null) {
                System.out.println("Serwer: " + linia);
                if (linia.contains("Oczekuje")) {
                    break;
                }
            }

            wysylka.println("P");

            while ((linia = odbior.readLine()) != null) {
                linia = linia.trim();
                if (linia.isEmpty()) continue;

                if (linia.contains("Podaj współczynnik")) break;


                String[] czesci = linia.split("\\s+");
                if (czesci.length != 2) continue;

                double x = parserZmieniacz(czesci[0]);
                double y = parserZmieniacz(czesci[1]);

                paryPunktow.put(x, y);
            }

            Map<Double, Double> wynik = metodaNajmniejszychKwadratow();
            Map.Entry<Double, Double> para = wynik.entrySet().iterator().next();
            double a = para.getKey();
            double b = para.getValue();

            wysylka.printf(Locale.US, "%.4f%n", a);
            wysylka.printf(Locale.US, "%.4f%n", b);
            //wysylka.flush();
            //System.out.println("Wysłano wynik: a=" + a + ", b=" + b);

            while ((linia = odbior.readLine()) != null) {
                System.out.println("Serwer: " + linia);
            }

        } catch (Exception e) {
            System.err.println("Błąd: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new NetLinearRegression().connectExecuteClose("172.30.24.12", 9090);
    }
}