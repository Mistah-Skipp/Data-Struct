import java.util.*;

class Node{
    String w;//w == hold data for string
    int n;//n == hold data for int
    public Node next;
    public Node(String word, int num){  //Constructor
        next = null;
        this.w = word;
        this.n = num;
    }

    public String toSTR(){
        return w +": " + n;
        //string: int       Word: Freq
    }

}//Node

public class LinkedList {
    public Node head;
    public int nodeCnt;
    public String compareWord;

    public LinkedList(){    //Constructor
        head = new Node(null, 0);
        nodeCnt = 0;
    }

    public void addLink(String w, int n){
        Node temp = new Node (w, n);
        Node current = head;
        if (current != null){//checks encase of NullPointerError
            while (current.next != null){
                current = current.next;
            }
        }
        current.next = temp;
        nodeCnt++;
    }

    public void printList(){    //prints out the entire linked list
        System.out.println("Linked List:");
        Node temp = head.next;
        while (temp != null){
            System.out.println(temp.w + ": "+ temp.n);
            temp = temp.next;
        }
    }//printlist

    public boolean  isListed(String w){
        Node temp =  head;

        if (temp != null){
            while (temp.next != null) {
                //if word is listed, return true
                compareWord = temp.w;
                if( w.equals(compareWord) ){return true;}
                temp = temp.next;
            }
        }
        //else return false
        return false;
    }//isListed

    public void updateNodeNum(String w){
        Node temp = head;
        while (temp.next != null){
            compareWord = temp.w;
            if (w.equals(compareWord)) {temp.n = temp.n +1;}
            temp = temp.next;
        }
    }//updateNodeNum

    public void sortingPrint(){
        Node agent = head;
        Node preAgent = null;
        //sort by freq
        while (agent != null){
            Node sorted = head;
            Node unsorted = null;
            if (agent != null) {
                while (sorted != agent){
                    if(sorted.n > agent.n){
                        unsorted = sorted;
                        sorted = sorted.next;
                    } else {
                        if (unsorted == null){
                            head = agent;
                            unsorted = head;
                        } else { unsorted.next = agent; }
                        preAgent.next = agent.next;
                        agent.next = sorted;
                        agent = preAgent;
                        break;
                    }
                }
            }
            preAgent = agent;
            agent = agent.next;
        }
        //printFreq
        Node temp = head;
        System.out.println("\nTop 30 Used Words");
        for (int i = 1;i <= 31;i++){
            System.out.println(temp.w + ": "+ temp.n);
            temp = temp.next;
        }
        //sort by word
        SortByWord();
    }//sortByFreq

    public void SortByWord(){
        int topCount = 0;
        Node tNode = head;
        HashMap<String, Integer> hmSort = new HashMap<>();
        for (int i = 1;i <= nodeCnt;i++){
            hmSort.put(tNode.w, tNode.n);
            tNode = tNode.next;
        }
        ArrayList<Map.Entry<String, Integer>> Sorter = new ArrayList<>(hmSort.entrySet());

        //Sorting via Word (Alphabetically)
        System.out.println("Sorted Via Word");
        Sorter.sort(Map.Entry.comparingByKey());
        for(Map.Entry<String, Integer> entry : Sorter) {
            // if the string contains none alphabetical chars it skips  so stuff like __word- or #123 dont print
            if (entry.getKey().matches("[a-z]+")) {
                System.out.println(entry.getKey() + ": " + entry.getValue());
                topCount++;
            }
            if (topCount == 30) break;
        }

    }

}//Linked List
