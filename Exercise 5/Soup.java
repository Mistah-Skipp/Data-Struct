import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.*;

public class Soup {
    public static void main(String [] args){
        String sightWords = "the is for and an a all at after I am";//words to not be printed
        String sentence;//holds the sentence from Scanner
        String [] words;//holds each word in a split sentence
        String delimiters = "\\s|\\?|\\,|\\!|\"|\\.|\\:|\\;";//whitespace , ? , comma , !, ", period, :, ;
        String[] SWList = sightWords.split(" ");
        int numSW = SWList.length;//number of Sight Words
        HashMap<String, Integer> hMap = new HashMap<>();
        HashTable HS = new HashTable (numSW);
        for (int count = 0; count < numSW; count++){
            //adds Sight words to the Hash Table
            HS.add(SWList[count].trim().toLowerCase()); }

        try {//reads from url -> reads line-by-line ->splits each line into indiviual words -> adds or incCnt to HashTable
            URL url = new URL("http://www.gutenberg.org/cache/epub/10900/pg10900.txt");
            Scanner reader = new Scanner(url.openStream());
            while (reader.hasNextLine()) {
                sentence = reader.nextLine();
                words = sentence.split(delimiters);

                for (String w : words) {
                    if(!HS.contains(w)){
                        if (w.strip().length() == 0)  continue;
                        w = w.toLowerCase();//convert w to lowercase

                        Integer n = hMap.get(w);
                        n = (n == null) ? 1 : ++n;// if n is null then iterate prior to adding
                        hMap.put(w, n);// pairs the string and int value together and puts into hMap
                    } else
                        HS.update(w);
                        //adds to the Hashmap of sight words rather instead of adding to hMap
                }

                //w == the actual word, words is the whole string of individual words
                //ADD HASHTABLE SHIT HERE!!!!!
            }
        } catch (MalformedURLException e) {// if invalid URL is given
            System.out.println("ERROR: Malformed URL");
        } catch (IOException e) {// if unexpected IO
            System.out.println("ERROR: IO Exception");
        }
//        for (int i= 0;i < numSW;i++)

        ArrayList<Map.Entry<String, Integer>> listOfEntries = new ArrayList<>(hMap.entrySet());
        Comparator<Map.Entry<String, Integer>> freqComparator = (elem1, elem2) -> elem2.getValue()-elem1.getValue();
        // sorting arraylist by frequency values using comparator
        Collections.sort(listOfEntries, freqComparator);
        int topCount = 0;
        //PRINT
        System.out.println("## Top 100 Used Words ##");
        for(Map.Entry<String, Integer> entry : listOfEntries){
            System.out.println(entry.getKey()+ ": "+entry.getValue());
            topCount ++;
            if (topCount == 100) break;
        }
    }
}

/*like hw 3 and 4 except custom hashtable
make custom hash set table
run thru text and if its not a sight word, add to list
    in hashtable fix unattended collision in add->else statement
get freq of top 100 words
*
https://repl.it/@StephenZhang2/hashingtable1
https://repl.it/@StephenZhang2/hashTable2
* */