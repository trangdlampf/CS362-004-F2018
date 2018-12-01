

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
	   String schemeArrayValid[] = {"http://", "ftp://", "h3t://", ""};
	   String schemeArrayInvalid[] = {"3ht://", "http:/", "http:", "http/", 
			   "://", "test://", "t://", "htp:/", "htpp://", "htp://",
			   "htpp:/"};
	   String authorityArrayValid[] = {"www.google.com", "go.com", "go.au",
			   "0.0.0.0", "255.255.255.255", "255.com"};
	   String authorityArrayInvalid[] = {"256.256.256.256", "1.2.3.4.5",
			   "1.2.3.4.", "1.2.3", ".1.2.3.4", "go.a", "go.1a", "go.a1a",
			   "aaa.", ".aaa", "aaa", ""};
	   String portArrayValid[] = {":80", ":65535", ":0", ""};
	   String portArrayInvalid[] = {":-1", ":65636", ":65a"};
	   String pathArrayValid[] = {"/test1", "/t123", "/$23", "/test1/", "",
			   "/test1/file"};
	   String pathArrayInvalid[] = {"/..", "/../", "/..//file", 
			   "/test1//file"};
	   String queryArrayValid[] = {"?action=view", "?action=edit&mode=up",
			   ""};
	   String queryArrayInvalid[] = {"????????", "?!@#@=edit&mode=down",
			   "?why?=help"};
	   
	   UrlValidator urlVal = new UrlValidator();
	   
	   for (String schemeString : schemeArrayValid) {
		   for (String authorityString : authorityArrayValid) {
			   for (String portString: portArrayValid) {
				   for (String pathString : pathArrayValid) {
					   for (String queryString : queryArrayValid) {
						   try {
						   assertTrue(urlVal.isValid(schemeString +
								   authorityString + portString + 
								   pathString + queryString));
					   } catch (Exception ex) {
						   System.out.println(ex);
					   	}
					   }
				   }
			   }
		   }
	   }
	   
	   for (String schemeString : schemeArrayInvalid) {
		   for (String authorityString : authorityArrayValid) {
			   for (String portString: portArrayValid) {
				   for (String pathString : pathArrayValid) {
					   for (String queryString : queryArrayValid) {
						   try {
						   assertTrue(urlVal.isValid(schemeString +
								   authorityString + portString + 
								   pathString + queryString));
					   } catch (Exception ex) {
						   System.out.println(ex);
					   	}
					   }
				   }
			   }
		   }
	   }
	   
   }
   


}
