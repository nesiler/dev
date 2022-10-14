static public void artPrint(boolean[][] toPrint, boolean printMirrorImage) {

        int i = 0, j = 0;

        for(; i < toPrint.length; i++){
        j = 0;
        for(; j < toPrint[0].length; j++){
        if(toPrint[i][j] == true)
        System.out.printf("X");
        else
        System.out.printf(" ");
        }

        if(printMirrorImage == true){

        for(int k = toPrint[0].length; k > 0; k--){
        if(toPrint[i][k-1] == true)
        System.out.print("X");
        else
        System.out.print(" ");
        }
        }

        System.out.println();
        }

        }
        }