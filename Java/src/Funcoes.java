import java.util.ArrayList;
import java.util.List;

public class Funcoes {
    // para achar mdc com recursiva
    int cont = 0;
    public int findMDCrecursiva(int n1, int n2, int aux){
        int mdc = 1;
        if(n1%aux == 0 && n2%aux == 0){
            mdc = aux; 
            return mdc;}
        else{
            this.cont++;
            mdc = findMDCrecursiva(n1, n2, n1 - cont);
            // System.out.println(cont);
            return mdc;
        }
    }
    public int x(int n){
        if((n == 1)||(n == 0)){
            return n;
        }
        else{
            return x(n-1)*n + x(n-2);
        }
    }

    public void trocar(int i, int j){
        int temp;
        temp = i; i = j; j = temp;
    }

    
    
}
