

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
	// testing Google URL without: /
   	final String MY_EMPTY_STRING_ARRAY1 = "http://www.google.com";
   	UrlValidator urlVal = new UrlValidator(null, null, 1);
	assertTrue(urlVal.isValid(MY_EMPTY_STRING_ARRAY1));
	assertTrue(urlVal.isValid("http://www.google.com"));
	assertTrue(urlVal.isValid("http://www.google.com/"));
	assertTrue(urlVal.isValid("http://go.com"));
	assertTrue(urlVal.isValid("http://go.com/"));
	assertTrue(urlVal.isValid("http://go.au"));   	 
	assertTrue(urlVal.isValid("http://go.au/")); 
	assertTrue(urlVal.isValid("http://go.a"));		// not valid
	assertTrue(urlVal.isValid("http://go.a1a"));  	// not valid 

   	// testing Go URL without: /
   	final String MY_EMPTY_STRING_ARRAY2 = "http://go.com";
   	UrlValidator urlVal2 = new UrlValidator(null, null, 1);
   	assertTrue(urlVal2.isValid(MY_EMPTY_STRING_ARRAY2));   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   
	   UrlValidator urlVal = new UrlValidator();
	   assertTrue(urlVal.isValid("http://www.google.com/search?source=hp"));  	//should pass
	   assertTrue(urlVal.isValid("hp://www.google.com/search?source=hp"));   	//should fail
	   assertTrue(urlVal.isValidScheme("http://"));   				// test scheme only

   }
   
   public void testYourSecondPartition()  //test authority
   {
	   UrlValidator urlVal = new UrlValidator();
	   assertTrue(urlVal.isValid("http://www.google.com/search?source=hp"));   	//should pass
	   assertTrue(urlVal.isValid("http://.google.com/search?source=hp"));    		//should fail
	   assertTrue(urlVal.isValidAuthority("www.google.com"));   			 //test authority only
   }
   
   public void testYourThirdPartition() 	 //test path
   {
	   UrlValidator urlVal = new UrlValidator();
	   assertTrue(urlVal.isValid("http://www.google.com/search?source=hp"));   	//should pass
	   assertTrue(urlVal.isValid("http://www.google.com/ ..search?source=hp"));   	//should fail
	   assertTrue(urlVal.isValidPath("/search"));    				//test path only  (passes)
   }
   
   public void testYourFourthPartition() 	 //test query
   {
	   UrlValidator urlVal = new UrlValidator();
	   assertTrue(urlVal.isValid("http://www.google.com/search?source=hp")); 	//should pass
	   assertTrue(urlVal.isValid("http://www.google.com/search?  source=hp")); 	//should fail
	   assertTrue(urlVal.isValidQuery("?source=hp"));   				 //test query only (passes)
   }
   
   public void testYourFifthPartition()  	//test a null string
   {
	   UrlValidator urlVal = new UrlValidator();
	   assertTrue(urlVal.isValid("http://www.google.com/search?source=hp")); 	//should pass
	   assertTrue(urlVal.isValid("")); 					//should fail
   }

   
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
	   
	   UrlValidator urlVal = new UrlValidator(null, null, 1);
	   
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
