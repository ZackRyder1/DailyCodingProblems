import java.util.HashMap;

public class Msg_Decoding {
    public static HashMap<Integer,Character> mappings = new HashMap<>();
    static {
        int a[] = new int [26];
        for(int i=1;i<=26;i++)
        {
            a[i-1] = i;
        }
        char c[] = new char[26];
        char s = 'a';
        for(int i=0;i<26;i++)
        {
            c[i] = s++;
            mappings.put(a[i],c[i]);
        }
    }
    public static void main(String[] args) {
//        mappings.forEach((k,v)->{
//            System.out.println(k+":"+v);
//        });
        String s ="123";
        decode_possibilities(s,"");
    }

    public static void decode_possibilities(String s,String result)
    {
        if(result == null)
            return;
        if(s.length() == 0)
        {
            System.out.println(result);
            return;
        }
        decode_possibilities(s.substring(1,s.length()),decode(String.valueOf(s.charAt(0)),result));
        if(s.length()>=2)
        {
            decode_possibilities(s.substring(2,s.length()),decode(s.substring(0,2),result));
        }
    }

    public static String decode(String encrypt,String result)
    {
            if(encrypt.length() == 2 && Integer.parseInt(encrypt)>=27 || Integer.parseInt(encrypt)== 0)
            {
                return null;
            }
            result+= mappings.get(Integer.parseInt(encrypt));
            return result;
    }

}
