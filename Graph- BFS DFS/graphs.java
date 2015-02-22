import java.util.LinkedList;
import java.util.Queue;


public class graphs {

        int num,i,j;
        int Max = 7;
        int matrixg[][] = new int[8][8];
        int visited[] = new int[8];

        public void printedge(){
                int i,j;
                for ( i=0 ; i<= Max ; i++)
                {
                        for (j=0 ; j<= Max ; j++)
                        {
                                System.out.print(matrixg[i][j] + " ");
                        }
                        System.out.println("");
                }
        }

        public void addedge(int vertex , int dest){
                if ( vertex > Max || dest > Max || vertex < 0 || dest < 0){
                        System.out.println("Invalid Edge Selected");
                }
                else{
                        matrixg[vertex][dest] = 1;
                        matrixg[dest][vertex] = 1;
            }
        }


        public void DFS(int num){

                int j;
                int i = num;
                System.out.println(i + " ");
                visited[i] = 1;
                for (j=0 ;j<= Max ; j++){
                        if (visited[j] == 0 && matrixg[i][j] == 1){
                                DFS(j);
                        }
                }
        
        }


        public static void main(String[] args){
        System.out.println("\nAdjacency matrix is as below ( 8 Node - 16 Edges)\n");
        graphs m = new graphs();
        m.addedge(1 , 4);
        m.addedge(0 , 4);
        m.addedge(1 , 2);
        m.addedge(0 , 7);
        m.addedge(0 , 5);
        m.addedge(4 , 7);
        m.addedge(1 , 3);
        m.addedge(4 , 5);
        m.addedge(2 , 6);
        m.addedge(3 , 5);
        m.addedge(5 , 1);
        m.addedge(7 , 3);
        m.addedge(0 , 3);
        m.addedge(6 , 4);
        m.addedge(1 , 7);
        m.addedge(5 , 6);
        
        m.printedge();
        System.out.println("\nDFS is as below");
        m.DFS(0);

        }}

