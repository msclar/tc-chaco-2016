import java.util.*;
import java.math.*;

class Main {
	public static void main (String [] argsMelYoTeAmo) {
		Scanner sc = new Scanner(System.in);
				
		int n;
		BigInteger[] dp = new BigInteger [10001];
		while (sc.hasNext()) {
			/* Primero decido si habra matching entre los nodos 0 y n-1 o no. Luego,
			   hacemos una dinamica para saber la cantidad de matchings en un grafo
			   linea (o sea, un ciclo menos un eje). 
	
			   dp[i] = cantidad de matchings en un grafo linea de i nodos
			*/

			n = sc.nextInt();
			
			dp[1] = BigInteger.valueOf(1);
			dp[2] = BigInteger.valueOf(2);

			for (int i = 3; i <= n; i++) {
				dp[i] = dp[i-1].add(dp[i-2]);
			}

			System.out.println(dp[n].add(dp[n-2]));
		}
	} 

}
