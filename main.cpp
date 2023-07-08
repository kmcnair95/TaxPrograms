// Kelton McNair
// May 10 2022
// CSCI 202 M08 Final Project
// This program is used to calculate the minimum witholdings on a W-4. You will enter your approximate income for a year, and the program will display to you the minmumum percentage of federal tax witholdings you should put on your W-4 to ensure you do not owe money in federal taxes at the end of the year, based on the provided income. ** Based on 2021 tax brackets ** changing to 2022 tax brackets doesn't require changes except for inside of the tax bracket function.

#include<iostream>
#include<cmath>
using namespace std;


void taxBrackets(float z) // this is the function that calculates tax brackets, witholdings percentages, and outputs it the user
{
float reportedIncome = z;
float approxAggregateIncome = reportedIncome -12550; // Subtracting the standard tax deduction from the reportedIncome. This is the standard deduction based on the cost of living. Itemized deductions or buisness deductions could be added in the future through different functions.

float running =approxAggregateIncome, apollo =0; // apollo is the current amount of taxes owed and approxAggregateIncome represents the user reportedincome-Standard deduction

  
    if (running > 0 && approxAggregateIncome > 0 ) // if income greater than 0// tax bracket 1
    {
      if (running >= 9950) // if you make more than 9950 in a year // tax bracket 1
        {
          running = running - 9950; // removing 9950 from running total
          apollo = apollo + 995; // adding 995$ in taxes

          if (approxAggregateIncome >= 9950 && running >0) // your total income is greater than 9950// tax bracket 2
            {
              if (running >30575)// tax bracket 2
                {
                  running = running -30575;// reducing the running total by 30575, tax bracket difference
                  apollo = apollo +3669; // this amount owed for 30575 at 12%

                  if(approxAggregateIncome >=40525 && running > 0)// tax bracket 3
                  {
                    if (running >45850)// tax bracket 3
                    {
                      running = running -45850; // tax bracket total range
                      apollo = apollo +10087; // the amount owed on the money in this bracket

                      if (approxAggregateIncome >= 86375 && running >0)// tax bracket 4
                        {
                          if (running > 78550)// tax bracket 4
                            {
                              running = running -78550;// tax bracket total range
                              apollo = apollo + 18852;// the amount owed on the money in this bracket

                              if (approxAggregateIncome >= 164925 && running >0)// tax bracket 5
                              {
                                if(running > 44500)// tax bracket 5
                                  {
                                    running = running -44500;// tax bracket total range
                                    apollo =  apollo +14240;// the amount owed on the money in this bracket

                                    if (approxAggregateIncome >= 204925 && running >0)// tax bracket 6
                                      {
                                        if (running > 314175)// tax bracket 6
                                          {
                                            running = running -314175;// tax bracket total range
                                            apollo = apollo +109961.25;// the amount owed on the money in this bracket

                                            if(approxAggregateIncome >=523600 && running >0) // tax bracket 7
                                            {
                                              apollo = apollo +(running*.37); // at this point we have removed 523600$ from the running balance and are applying a 37 percent tax to anything over 523600$
                                            }
                                                                                
                                          }
                                        else // this activate if you make equal to or less than 523600 in a year but more than 209425
                                          {
                                            apollo = apollo +(running *.35); // this is the 35 percent tax on income above 164925 being added up until your total income
                                          }
                                      }
                                  }
                                else // this activates if you make equal to or less than 209425 in a year but more than 164925
                                  {
                                    apollo = apollo + (running *.32); // this is the 32 percent tax on income above 164925 being added up until your total income
                                  }
                              }
                            }
                          else // this activates if you make equal to or less than 164925 in a year but more than 86375
                            {
                              apollo = apollo +(running*.24); // this is the 24 percent tax on income about 86375 being added up until your total income
                          
                            }
                        }                        
                    }
                    else // this activates if you make equal to or less than 86375 in a year but more than 40525
                    {
                      apollo = apollo + (running*.22); // this is the adding the 22% tax on everything above 40525 in the third tax bracket, up until your income
                    }
                  }              
                }
              else // this activates if you make equal to or less than 40525 in a year but more than 9950
                {
                  apollo = apollo + (running*.12); // this is for if approx annual income is greater than 9950 and less than 40525, you pay 10% taxes on 9950 and then 12 on everything above that below 40525
                }
            }            
        }
      else // this activates if you make equal to or less than 9950 in a year
        {
          apollo = running*.1; // this is for if the approximate income is less than 9950 per year, you pay 10% taxes on 9950
        }
    }
cout<< "\n";
cout << "Estimate Federal Tax Paid on an Anunual Salary of:"<< reportedIncome<< ". Is: " << apollo;
cout<< "\n";
cout << "That means you should select a minimum W-4 federal witholdings amount of: "<< 100*(apollo/reportedIncome) << "%";
cout<< "\n";




  

};

void plusMinus(int z, int y) // this function is used to recursively call the taxBrackets function for the amount of iterations that would benefit the user based on their +/- income amount entered
{
  double totalNumber = y; // this is the amount the user specifies to be +/- their income
  float reportedZ =z; // this is the reported approx annual income of the user

  double totalNumberOfRecursions = totalNumber/5; // this is creating the recursive iteration amounts to give the user +/- x10 a portion of the amount they entered to be added or removed from their income

  int alpha=5, beta=1; // these are counter variables
  

  
  do
    {
      double recursionCounterPositive = totalNumberOfRecursions*alpha; // incremental amount used for adjusting income
      taxBrackets(reportedZ+recursionCounterPositive); // recursive call
        --alpha;
    }while(alpha>0); // this loop recursively calls the taxBrackets function with the addition of the amount entered by the user to be +/- their income, it does it split into increments of 5


 importantNext:taxBrackets(reportedZ); // singular call to output the W4 witholdings for the users original input approx income


 do
    {
      double recursionCounterNegative = totalNumberOfRecursions*beta;// incremental amount used for adjusting income
      taxBrackets(reportedZ-recursionCounterNegative);// recursive call
        ++beta;
    }while(beta<6);// this loop recursively calls the taxBrackets function with the subtraction of the amount entered by the user to be +/- their income, it does it split into increments of 5

};


int main()
{
  cout <<"This program is to help educate employees on how much federal income tax witholdings they should assign on their W-4.\nWhen selecting a portion of income to withold, it can be misleading what percentage to select.\n";
  cout <<"This program is going to ask the user for two types of information:\n1.) Their current annual approximate income\n2.) An additional +/- income they may gain or lose, so that the program can calculate for that amount aswell through recursion\n";
  
  int z=0;



  cout << "\nPlease enter your Annual Approximate Income\n";
  cin >> z;

      while (!(z && z >= 0.00 && z <= 2147483647)) // input validation
    {
      cout << "Please enter a number larger than zero. Invalid input, try again\n";
                  cin.clear ();
                  cin.ignore(2147483647, '\n');
                  cin >> z;
    };

  cout <<"\nPlease enter an approximate amount of income you may gain or lose this year.\nIf you may get a raise of 10%, and you make 50000, enter 5000.\nOr if you plan on taking a month long vacation and you make 50000, you would remove 9% meaning, enter 4000\n";


  int y =0;
  cin >> y;


        while (!(y && y >= 5.00 && y <= 2147483647))// input validation
    {
      cout << "Please enter a number larger than five. Invalid input, try again\n";
                  cin.clear ();
                  cin.ignore(2147483647, '\n');
                  cin >> y;
    };

  
//taxBrackets(z);


plusMinus(z,y); // call to the recursive function with the two important values

  
  return 0;
};



















