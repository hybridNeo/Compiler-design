Group Details:MEMBER 1:USN:1PI12IS112,NAME:Subbulakshmi Alias Subha
			  MEMBER 2:USN:1PI12IS107,NAME:Sonali Jagdish

How to execute the program: The code is executed using the command python asn1.py -f file_name.Here we are using python2 and not python 3.The .txt file which is the input to the program should be given as 
						  as a command line argument.
 
			  
			  
How The Program Works:We have used  pretty straightforward approach.So the program takes the input from the command prompt
                      which is a file.Since the first line of the input file has details of description of different columns in the file we ignored it by reading a line and then running a for loop from second line till the end of the file.
					  As and when each line is read ,the line is split using ',' as the delimiter.We unpacked it and split the first value from the rest because the product no was not required for calculation.
					  We created a list named array which has details of all the products.Inside the while loop we created another list which had details of individual products,each value from file was appended in the list named 'list'.
			          The number in the second column from left in the file represents the no of people who rated 5 stars ,3rd column no of users who rated 4stars and so on.When values for a product were read the total no of users was calculated 
					  The individual sum was calculated by calling a separate function by multiplying the no of users who rated a specific rating with the rating i.e(5 stars,4 stars,...) and this individual sum is appended into the individual_sum list and individual average is 
					  calculated by dividing the individual sum by the no of users which is another list containing the no of users of each product.Total sum is calculated by finding sum of individual sum of all products and individual average by dividing the total sum by a the sum of the users list.
					  Bayesian average for individual product is calculated using the Bayesian formula Adjusted Bayesian average is calculated by using the api sort(list) 
					  to put the Bayesian average in ascending order and then reversed to sort it in descending order.To print the product no with the corresponding Bayesian average we created a list named dupli 
					  having the copy of Bayesian average list .So we mapped the adjusted Bayesian average list and dupli list to get the product no.
				
				
Challenges encountered:    1.Initially we didnt read the question fully so wrote the code in which the input is taken from user.Later we wrote the code in which input is a file
						   2.When we read file and put the items in the list and displayed the list a '\n' was appended at the end of each list ,So we got rid of that when we used the split function to split the values which were separated by ','
						   3.initially as and when values were read from the file we kept appending to the list and passed it to respective functions to compute different values but for all the products it kept taking the most recent product entry 
			                 so all the answers were same ,so later we kept calculating everything in the same main function except for one ,and it turned out to be right.
						   4.For calculating the individual average we initially divide by 5 because there are five ratings then we changed to total no of users.
						   5.In one of the places we had to create a nested list but declared both the lists outside so it wasnt working properly,later we corrected that
						   6.In one of the place we had to reinitialise a variable in the loop else it went out of bound ,we reinitialised it when it didnt work well
						   7.while using the getopt command to take input from command line we had passed a wrong invalid argument which was rectified later.

	