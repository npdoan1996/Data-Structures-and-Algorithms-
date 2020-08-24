import java.io.File;  // Import the File class
import java.io.FileNotFoundException;  // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files

public class assignment3 {
    public static void main(String[] args) {
        try {
            HashSet<String> HS = new HashSet<String>(50);
            int wordCount = 0;
            File myObj = new File("trump_speech.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNext()) {
                String word = myReader.next().replaceAll("[^a-zA-Z0-9]", "");
                if (!word.equals("")){
                    HS.add(word);
                    wordCount++;
                }
            }
            System.out.printf("Words count: %d\n", wordCount);
            System.out.printf("Distinct words: %d\n", HS.count());
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
      }
}