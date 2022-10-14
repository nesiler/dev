public class CSEException extends Exception {
    public CSEException(int errorCode) {
        super("CSE Exception " + errorCode);
    }

    public static void main(String[] args) {
        try {
            throw new CSEException(6);
        } catch (CSEException e) {
            System.out.print(e.getMessage());
        } catch (Exception e) {
            System.out.print(" some exception");
        }
    }
}