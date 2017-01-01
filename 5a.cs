using System;
using System.Text;
using System.Linq;
using System.Security.Cryptography;

public static class Task5{
	public static string CalculateMD5Hash(string input)
	{	
    		MD5 md5 = System.Security.Cryptography.MD5.Create();
	   	byte[] inputBytes = System.Text.Encoding.ASCII.GetBytes(input);
   		byte[] hash = md5.ComputeHash(inputBytes);
   		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < hash.Length; i++)
   		{
			sb.Append(hash[i].ToString("X2"));
		}
   		 return sb.ToString();
	}
	public static void Main(){
		string str="abbhdwsy";
		int append=0;
		StringBuilder built=new StringBuilder();
		while(built.Length<8){
			string temp=CalculateMD5Hash(str+(++append));
			if(temp.Substring(0,5).All(c=>c=='0')){
				built.Append(temp[5]);
				Console.Write(built.Length);
				Console.Write(":");
				Console.Write(built.ToString());
				Console.Write("   "+append.ToString());
				Console.WriteLine();
			}
		}
		Console.WriteLine(built.ToString());
		
	}
}
