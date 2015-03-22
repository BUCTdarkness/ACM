public class Solution {
    public boolean isNumber(String s) {
 		s=s.toLowerCase();
 		try{
 			Double.parseDouble(s);
 		}
 		catch(Exception e){
 			return false;
 		}
 		return s.charAt(s.length()-1)!='f'&& s.charAt(s.length()-1)!='d';      
    }
}