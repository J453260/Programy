import java.util.function.Function;
import java.util.concurrent.atomic.AtomicInteger;

public class MultithreadedIntegaration implements ParallelIntegaration{
    private Function<Double, Double> funkcja;
    private int liczbaWatkow;
    private double suma = 0.0;
    int subintervals;
    private final Object zamekIndeks = new Object();
    private final Object zamekSuma = new Object();


    @Override
    public void setFunction(Function<Double, Double> function){
        this.funkcja = function;
    }

    @Override
    public void setThreadsNumber(int threads){
        this.liczbaWatkow = threads;
    }

    @Override
    public void calc(Range range, int subintervals){
        this.subintervals = subintervals;
        double start = range.min();
        double koniec = range.max();
        double szerokosc = (koniec - start) / subintervals;

        Thread[] watki = new Thread[liczbaWatkow];
        double[] czesciowyWynik = new double[liczbaWatkow];
        AtomicInteger nastepny = new AtomicInteger(0);

        int iloscProstokatow = Math.max(1, subintervals / (liczbaWatkow * 16));

        for(int i = 0; i < liczbaWatkow; i++){
            int ID = i;

            watki[i] = new Thread(() -> {
                double czesciowaSuma = 0.0;

                while (true) {
                    int startowy, koncowy;
                    startowy = nastepny.getAndAdd(iloscProstokatow);
                    if (startowy >= subintervals) {
                        break;
                    }

                    koncowy = Math.min(startowy + iloscProstokatow, subintervals);

                    for (int j = startowy; j < koncowy; j++) {
                        double x = start + (j + 0.5) * szerokosc;
                        czesciowaSuma += funkcja.apply(x);
                    }
                }

                synchronized (zamekSuma) {
                    czesciowyWynik[ID] = czesciowaSuma;
                }
            });

            watki[i].start();
        }

        for (Thread t : watki) {
            try {
                t.join();
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }

        suma = 0.0;
        for(double czS : czesciowyWynik){ //czS - częściowa Suma
            suma += czS;
        }
        suma *= szerokosc;
    }

    @Override
    public double getResult(){
        return suma;
    }
}
