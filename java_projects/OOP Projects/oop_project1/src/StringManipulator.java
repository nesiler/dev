/**
 * manipulates a string
 *
 * @dilerenes
 */
public class StringManipulator {

    public static void main(String[] args) {

		/*This part is not tested and graded.
		You can try to manually test your program from here
		bu kisim proje kapsaminda degerlendirilmeyecektir.
		*/

        StringManipulator manipulator = new StringManipulator();
        System.out.println(manipulator.findInitials("M.Enes Diler"));
        System.out.println(manipulator.changeExtension("deneme.java", "txt"));

    }

    /**
     * returns intiail of the given name
     * e.g.: if name is "ALI VELI", it returns "AV".
     * Verilen ismin bas harflerini bulur, ornegin "Ayse Fatma" icin
     * "AF" return eder
     * ismin sadece 2 kelimeden olustugunu varsayabilirsiniz.
     *
     * @param name
     * @return the initials
     */

    String findInitials(String name) {
        if (name.length() == 0)
            return "There is no name here!";


        String initials = "" + Character.toUpperCase(
                name.charAt(0));

        for (int i = 1; i < name.length() - 1; i++) {
            if (name.charAt(i) == ' ' || name.charAt(i) == '.') {
                initials += (Character.toUpperCase(name.charAt(i + 1)));
            }
        }

        return initials;
    }

    /**
     * changes the extension of the filename
     * e.g. if filename is "data.txt" and ext is "java"
     * it returns "data.java"
     * tr: verilen dosyanin uzantisini degistirir. Ornegin
     * e.g.  filename icin "data.txt" ve ext icin "java" verilirse
     * "data.java" yi  return eder
     *
     * @param filename
     * @param ext
     * @return
     */

    String changeExtension(String filename, String ext) {

        int index = filename.lastIndexOf(".");

        String fn = filename.substring(0, index) + "." + ext;

        return fn;

    }


}
