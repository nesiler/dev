import java.util.Locale;
import java.util.Scanner;

/**
 * Project 2 -- Cipher
 * <p>
 * This is an implementation of encryption and decryption algorithms of a
 * substitution cipher
 *
 * @author your name
 * @class BIL 122
 * @date date of completion
 */


public class Cipher {

    final String plaintextAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // Plaintext
    private final String ciphertextAlphabet; // Ciphertext Alphabet
    // Alphabet
    private String keyword; // The Secret Keyword

    /**
     * Class constructor initializes the keyword and creates the Ciphertext Alphabet
     *
     * @param key the secret keyword used to create the ciphertext alphabet
     */
    public Cipher(String key) {

        keyword = key;
        ciphertextAlphabet = initCiphertextAlphabet();

    }

    /**
     * removes all duplicate occurrences of characters from a String
     *
     * @param s String with duplicate occurrences of characters
     * @return String with no duplicate characters in it
     */
    public static String removeDups(String s) {

        String noDups = "";

        for (int i = 0; i < s.length(); i++) {

            if (!noDups.contains(String.valueOf(s.charAt(i)))) {
                noDups = noDups.concat(String.valueOf(s.charAt(i)));
            }

        }

        return noDups;

    }

    public static void main(String[] args) {

        Cipher cipher = new Cipher("qwertyuiopasdfghjklzxcvbnm");

        String message, encryptedMessage, decryptedMessage, alyhan;
        Scanner scan = new Scanner(System.in);


        System.out.println("Normal Alfabe: " + cipher.plaintextAlphabet);
        System.out.println("Şifreli Alfabe: " + cipher.ciphertextAlphabet);

        System.out.println("Enter the message:");
        message = scan.nextLine();

        encryptedMessage = cipher.encrypt(message);

        System.out.println("Şifrelenmiş mesaj:" + encryptedMessage);

        //System.out.println("Enter the message:");
        //alyhan = scan.nextLine();

        //decryptedMessage = cipher.decrypt(encryptedMessage);

        //alyhan = cipher.decrypt(alyhan);
        //System.out.println("Çözülmüş Mesaj:" + alyhan);


        //System.out.println("Enter the encrypted message:");
        //ciphermessage = scan.nextLine();


    }

    /**
     * generates the ciphertext alphabet from the keyword
     *
     * @return String of ciphertext alphabet generated from the keyword
     */
    public String initCiphertextAlphabet() {

        keyword = keyword.toUpperCase(Locale.ROOT);

        for (int i = 0; i < plaintextAlphabet.length(); i++) {

            if (!keyword.contains(String.valueOf(plaintextAlphabet.charAt(i)))) {
                keyword = keyword.concat(String.valueOf(plaintextAlphabet.charAt(i)));
            }
        }

        keyword = removeDups(keyword);
        return keyword;

    }

    /**
     * Encrypts a message in plaintext
     *
     * @param message the message to be encrypted in ciphertext alphabet
     * @return the encrypted message in ciphertext alphabet
     */
    public String encrypt(String message) {

        message = message.toUpperCase(Locale.ROOT);
        int index;
        String ch;
        String encryptedMessage = "";

        for (int i = 0; i < message.length(); i++) {

            if (plaintextAlphabet.contains(String.valueOf(message.charAt(i)))) {

                index = plaintextAlphabet.indexOf(message.charAt(i));
                ch = String.valueOf(ciphertextAlphabet.charAt(index));
                encryptedMessage = encryptedMessage.concat(ch);

            } else {

                encryptedMessage = encryptedMessage.concat(String.valueOf(message.charAt(i)));

            }

        }

        return encryptedMessage;

    }

    /**
     * Encrypts a message in plaintext
     *
     * @param ciphertext ciphertext in ciphertext alphabet
     * @return the decrypted message in plaintext alphabet
     */
    public String decrypt(String ciphertext) {

        ciphertext = ciphertext.toUpperCase(Locale.ROOT);

        int index;
        String ch;

        String decryptedMessage = "";

        for (int i = 0; i < ciphertext.length(); i++) {

            if (ciphertextAlphabet.contains(String.valueOf(ciphertext.charAt(i)))) {

                index = ciphertextAlphabet.indexOf(ciphertext.charAt(i));
                ch = String.valueOf(plaintextAlphabet.charAt(index));
                decryptedMessage = decryptedMessage.concat(ch);

            } else {

                decryptedMessage = decryptedMessage.concat(String.valueOf(ciphertext.charAt(i)));

            }
        }

        return decryptedMessage;

    }

}
