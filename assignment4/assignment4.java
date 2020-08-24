import java.io.File; // Import the File class
import java.io.FileNotFoundException; // Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files

public class assignment4 {
  public static void main(String[] args) {
    try {
      RedBlackTreeMap<String, Integer> RBtree = new RedBlackTreeMap<String, Integer>();
      int lineCount = 0;
      File myObj = new File("players_homeruns.csv");
      Scanner myReader = new Scanner(myObj);
      while (myReader.hasNext() && lineCount < 5) {
        String line = myReader.nextLine();
        String[] components = line.split(",");
        RBtree.add(components[0], Integer.parseInt(components[1]));
        if (!line.equals("")) {
          lineCount++;
        }
      }
      System.out.println("Test 1: Added the first 5 lines");
      RBtree.printStructure();
      System.out.println();
      while (myReader.hasNext() && lineCount < 10) {
        String line = myReader.nextLine();
        String[] components = line.split(",");
        RBtree.add(components[0], Integer.parseInt(components[1]));
        if (!line.equals("")) {
          lineCount++;
        }
      }
      System.out.println("Test 2: Added the next 5 lines");
      RBtree.printStructure();
      System.out.println("Now call the find method on four different key in the tree  with the first 10 elements");
      System.out.printf("One key that is a leaf: Key = %s || Value = %d\n", "Babe Ruth", RBtree.find("Babe Ruth"));
      System.out.printf("One key that is a root: Key = %s || Value = %d\n", "Honus Wagner",
          RBtree.find("Honus Wagner"));
      System.out.printf("One key that has a NIL and a non-NIL child: Key = %s || Value = %d\n", "Rogers Hornsby",
          RBtree.find("Rogers Hornsby"));
      System.out.printf("One key that is a red node: Key = %s || Value = %d\n", "Ted Williams",
          RBtree.find("Ted Williams"));
      System.out.println();

      while (myReader.hasNext()) {
        String line = myReader.nextLine();
        String[] components = line.split(",");
        RBtree.add(components[0], Integer.parseInt(components[1]));
        if (!line.equals("")) {
          lineCount++;
        }
      }
      System.out.println("Test 3: Added the remaining lines");
      System.out.println("Call the find method on four different key in the entire tree");
      System.out.printf("One key that is a leaf: Key = %s || Value = %d\n", "Babe Ruth", RBtree.find("Babe Ruth"));
      System.out.printf("One key that is a root: Key = %s || Value = %d\n", "Honus Wagner",
          RBtree.find("Honus Wagner"));
      System.out.printf("One key that has a NIL and a non-NIL child: Key = %s || Value = %d\n", "Rogers Hornsby",
          RBtree.find("Rogers Hornsby"));
      System.out.printf("One key that is a red node: Key = %s || Value = %d\n", "Ted Williams",
          RBtree.find("Ted Williams"));
      System.out.println();
      System.out.printf("The number of distinct key : %d\n", RBtree.getCount());
      // System.out.println(RBtree.containsKey("Rod Carew"));

      myReader.close();
    } catch (FileNotFoundException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
  }
}