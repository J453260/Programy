import java.util.*;

public class MultithreadedTaskProcessor implements TaskProcessor{
    public int threadLimit;
    int nastepneZadanie = 0; //do uruchomienia
    int nastepneDoZapisania = 0;
    List<Task> tasks;
    ResultConsumer consumer;
    List<Runnable> workers = new ArrayList<>();
    Map<Integer, Integer> result = new HashMap<>();
    private final Object lock = new Object();
    List<Thread> watki;

    Runnable run = () -> {
        while(true){
            int index;
            synchronized(lock){
                if(nastepneZadanie >= tasks.size()){
                    break;
                }

                index = nastepneZadanie;
                nastepneZadanie++;
            }

            int wynik = tasks.get(index).result();

            synchronized(lock){
                result.put(index, wynik);

                while(result.containsKey(nastepneDoZapisania)){
                    consumer.save(
                            tasks.get(nastepneDoZapisania).id(),
                            result.get(nastepneDoZapisania)
                    );
                    result.remove(nastepneDoZapisania);
                    nastepneDoZapisania++;
                }
                //lock.notifyAll();
            }
        }
    };

    @Override
    public void set(List<Task> tasks, ThreadsFactory factory, ResultConsumer consumer){
        this.tasks = tasks;
        this.consumer = consumer;
        nastepneZadanie = 0;
        nastepneDoZapisania = 0;
        workers.clear();
        result.clear();
        for(int i=0; i<threadLimit; i++){
            workers.add(run);
        }

        watki = factory.createThreads(workers);

        for(Thread t : watki){
            t.start();
        }

        try {
            for(Thread t : watki){
                t.join();
            }
        } catch (InterruptedException e) {
        }
    }

    @Override
    public void threadsLimit(int limit){
        this.threadLimit = limit;
    }
}