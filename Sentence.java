import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Sentence {
    static boolean reconstruct = false;
    static String [] constructed;
    static final HashSet<String> valid_words = new HashSet<>();

    static void init(String [] word)
    {
        valid_words.addAll(Arrays.asList(word));
        constructed = new String[valid_words.size()];
    }

    static void reBuild(String joined,int itr)
    {
        if(joined.length() == 0) {
            reconstruct = true;
            return;
        }

        StringBuilder s = new StringBuilder();
        for(int i=0;i<joined.length();i++)
        {
            s.append(joined.charAt(i));
            if(valid_words.contains(s.toString()))
            {
                constructed[itr] = s.toString();
                reBuild(joined.substring(i+1,joined.length()),itr+1);
                if(reconstruct)
                    return;
            }
        }
    }

    public static void main(String[] args) {
        String words[] = {"bedbath","bed","bath", "and", "beyond"};
        String joined = "bedbathandbeyond";
        init(words);
        reBuild(joined, 0);
        if (reconstruct) {
            System.out.println("The sentence is :");
            for (String s : constructed)
            {
                if(s == null)
                    break;
                System.out.print(s + " ");
            }

            System.out.println();
        }
        else
            System.out.println("Can't Construct the above sentence");

    }
}
