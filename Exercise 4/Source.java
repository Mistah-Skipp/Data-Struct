import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Scanner;
public class Source {
    public static void main(String[] args){
        String sentence;
        String [] words;
        String delimiters = "\\s|\\?|\\,|\\!|\"|\\.|\\:|\\;";//whitespace , ? , comma , !, ", period, :, ;
        int wordCnt = 0;
        LinkedList LList = new LinkedList();
        LList.head = new Node(null, 0);

        //if new word, make a new node else increment that nodes n (int data)
        try {
            URL url = new URL ("https://www.gutenberg.org/cache/epub/33180/pg33180.txt");
            Scanner reader = new Scanner (url.openStream());
            while (reader.hasNextLine()){
                sentence = reader.nextLine();
                words = sentence.split(delimiters);
                wordCnt += words.length;

                for (String w : words) {
                    if (w.strip().length() == 0)  continue;
                    w = w.toLowerCase();//convert w to lowercase
                    if (LList.isListed(w)){
                        //if the word is in the list, updates node freq value
                        LList.updateNodeNum(w);
                    } else {
                        //if word isnt in list, adds new node with freq 1
                        LList.addLink(w, 1);
                    }
                }
            }
        } catch (MalformedURLException e) {// if invalid URL is given
            System.out.println("ERROR: Malformed URL");
        } catch (IOException e) {// if unexpected IO
            System.out.println("ERROR: IO Exception");
        }
        System.out.println("Total word Count: "+ wordCnt);
        //LList.printList();

        LList.sortingPrint();



        System.out.println("Done!");
    }//main_END
}
