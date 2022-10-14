import java.util.Locale;

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
    // Alphabet
    private String keyword; // The Secret Keyword
    private String ciphertextAlphabet; // Ciphertext Alphabet

    /**
     * Class constructor initializes the keyword and creates the Ciphertext Alphabet
     *
     * @param key the secret keyword used to create the ciphertext alphabet
     */
    public Cipher(String key) {
        this.keyword = key;
        ciphertextAlphabet = initCiphertextAlphabet();

    }

    /**
     * removes all duplicate occurrences of characters from a String
     *
     * @param s String with duplicate occurrences of characters
     * @return String with no duplicate characters in it
     */
    public static String removeDups(String s) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (!result.toString().contains(String.valueOf(s.charAt(i)))) {
                result.append(String.valueOf(s.charAt(i)));
            }


        }

        return result.toString();

    }

    /**
     * generates the ciphertext alphabet from the keyword
     *
     * @return String of ciphertext alphabet generated from the keyword
     */
    public String initCiphertextAlphabet() {
        keyword = keyword.toUpperCase(Locale.ROOT);

        keyword = keyword.concat(plaintextAlphabet);

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

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < message.length(); i++) {
            if (plaintextAlphabet.contains(String.valueOf(message.charAt(i)))) {
                int x = plaintextAlphabet.indexOf(message.charAt(i));
                result.append(String.valueOf(ciphertextAlphabet.charAt(x)));
            } else
                result.append(String.valueOf(message.charAt(i)));


        }

        return result.toString();

    }

    /**
     * Encrypts a message in plaintext
     *
     * @param ciphertext ciphertext in ciphertext alphabet
     * @return the decrypted message in plaintext alphabet
     */
    public String decrypt(String ciphertext) {
        ciphertext = ciphertext.toUpperCase(Locale.ROOT);
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < ciphertext.length(); i++) {
            if (plaintextAlphabet.contains(String.valueOf(ciphertext.charAt(i)))) {
                int x = ciphertextAlphabet.indexOf(ciphertext.charAt(i));
                result.append(String.valueOf(plaintextAlphabet.charAt(x)));
            } else
                result.append(String.valueOf(ciphertext.charAt(i)));
            if (i == ciphertext.length() - 1) break;
        }
        return result.toString();

    }

}