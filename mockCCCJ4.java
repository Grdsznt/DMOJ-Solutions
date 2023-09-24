import java.io.*;
import java.util.*;
public class mockCCCJ4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        
        String[] NS = br.readLine().trim().split(" ");
        
        List<pair> list = new ArrayList<>();
        int numgrps = Integer.parseInt(NS[0])/Integer.parseInt(NS[1]), totalMatch = ((Integer.parseInt(NS[1])-1)*Integer.parseInt(NS[0]))/2;
        String[][] matches = new String[numgrps][Integer.parseInt(NS[1])*2];
        int[] points = new int[Integer.parseInt(NS[0])];
        for (int i = 0;i<numgrps;i++) {
            String[] countries = br.readLine().trim().split(" ");
            int pointer = 0;
            for (int j = 0;j<countries.length*2;j += 2) {
                matches[i][j] = countries[pointer];
                pointer++;
            }
            //group num is just matches[] row num

        }
        // Collections.sort(a, (x, y) -> {
        //     if (x.ai-x.bi!=y.ai-y.bi) {
        //         return Integer.compare(x.ai-x.bi, y.ai-y.bi);
        //     } else  {
        //         return Integer.compare(x.ai, y.ai);
        //     }
        // }); practise
        //positive compare means ascending, negative means descending
        Collections.sort(list, (x, y) -> {if (x.score != y.score) return -Integer.compare(x.score, y.score); else return Integer.compare(x.team, y.team);});
        Collections.sort(list, (x, y) -> {
			if(x.score != y.score)
				return -Integer.compare(x.score, y.score);
			else 
				return Integer.compare(x.team, y.team);
		});

        for (int k = 0;k<totalMatch;k++) {
            String[] match = br.readLine().trim().split(" ");
            if (match[2].contains("W")) {
                points[Integer.parseInt(match[0])] += 3;
            } else if(match[2].contains("T")) {
                ++points[Integer.parseInt(match[0])];
                ++points[Integer.parseInt(match[1])]; 
            } else {
                points[Integer.parseInt(match[1])] += 3; 
            }
        }
        String contcant = "";
        int[] print = new int[numgrps];
        int[] sorted = Arrays.copyOf(points, points.length);
        Arrays.sort(sorted);
        //basically for the point array just put the country in the second
        // int kth = Integer.parseInt(next());
        // for (int l = 0;l<numgrps;l++) {
        //     // for each group in the comp, we check for kth element and print
        //     int temp = 0;
        //     // kth country
        //     sorted
        //     //in the sorted array, gwt all multiples of kth possible
        //     sorted[l];
        //     //l+1 is the ranking
        //     for (String s: matches[l]) {
        //         int point = points[Integer.parseInt(s)-1];
        //         print[l] = Arrays.asList(sorted).indexOf(point);
        //         if (sorted[] == kth) {

        //         }
        //     }
        //     for (int m = 0;m < matches.length;m++) {
        //         if(points[m] =)
        //     }
        // }


    }
    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
    static class pair {
        int score, team;
        pair(int s , int t) {score = s;team = t;}
    }
}
// for (int i = 0;i<pts.length;i++) {


// for (int k = 0;i<matches.length;i++) {
    // for (int j = 0;j<matches[0].length) {
    //     if matches[j][k] = i+1 {
        //  newarr[i] = k+1;
            // break;
    
    // }
//       
//       
//}