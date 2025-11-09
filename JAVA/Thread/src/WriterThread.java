public class WriterThread implements Runnable {
    Risorsa risorsa;
    int num;

    public WriterThread(Risorsa r, int num) {
        this.risorsa = r;
        this.num = num;
    }

    @Override
    public void run() {
        this.risorsa.initialize(this.num);
    }
}