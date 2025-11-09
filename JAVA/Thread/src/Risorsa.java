public class Risorsa {
    private int[] arr;
    private int BOUND;

    public Risorsa(int B) {
        this.BOUND = B;
        this.arr = new int[BOUND];
    }

    public void initialize(int n) {
        for (int i = 0; i < BOUND; i++) {
            arr[i] = n;
        }
    }

    public int[] getArr() {
        return arr;
    }
}