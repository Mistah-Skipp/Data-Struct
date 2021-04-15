import java.util.ArrayList;

public class HashTable {
    private ArrayList<String> words;
    private int[]freq;
    private int HTsize;
    int cnt;// word/freq array size counter , counts number of used spots essentially
    int homeIDX;//get the index of the word

    HashTable(int HTsize){
        //sets array size, words[size] & freq[size] are made and basic vars are initalized (counter and exist flag)
        this.HTsize = HTsize;
        words = new ArrayList<>(HTsize);
        freq = new int[HTsize];
        cnt = 0;

    }//HashTable_END

    void add(String word){
    //Adds word to hashTable
        homeIDX = Math.abs(hashNum(word))%HTsize;
        words.add(word);
    }//add_END

    boolean contains (String word){
    //checks if word is in the list
        for(int i = 0; i < words.size();i++){
            if (words.get(i).equals(word)){
               return true;
            }
        }
        return false;

    }//contains_END

    void update(String word){
        for(int i = 0; i < words.size();i++) {
            if (words.get(i).equals(word))
                freq[i] += 1;
        }


    }//updated_END

    //debugging purpose
    void print(){
        for(int i = 0; i < HTsize; i++)
            System.out.println(words.get(i) + ": " + freq[i]);
    }//print_END

    //gets hash key (using built in function, future builds will add up the ascii codes for the letters in the word
    int hashNum(String word){ return word.hashCode(); }//hashNum_END

}
