public class fenwickTree{

    static int[] bit = new int[100001];
    public static void main(String[] args) {
        
    }

    static long query(int indx){
        long sum = 0;
        while(indx > 0){
            sum += bit[indx];
            indx -= indx & -indx;
        }
        return sum;
    }

    static void update(int indx, int val){
        while (indx <= bit.length-1){
            bit[indx] += val;
            indx += indx & -indx;
        }
    }
    
}