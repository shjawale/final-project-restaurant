 
 > Title:  Cash Register Application
 > Authors: \<[Ethan Bayer](https://github.com/EthanBayer)\> + \<[Bryan Guevara](https://github.com/Guevara-Bryan)\> + \<[Shruti](https://github.com/blank)\>

 > Description:
 > *As a group we have decided to create a cash register application as we are all College students and with that title comes a great deal of debt and so many college students get part time jobs to help with the rising costs. While, one part time job we are all familiar with is being a cashier and so we thought it might be interesting to design our own software in simulating a cash register and see how it holds up to company certified cash register software. 
 > *In terms of tools we will be using, we are going to be using C++ as our primary language and using PUTTY, or in general a command line console, to implement our text based csah register program, however if time allows we will also see if we can create a GUI for our software.
> *We forsee the overall input of our software being the Items a Customer is purchasing and the Payment they will use to purchase their Items, while in terms of output we will need to display the Item being scanned and the cost to the Customer, along with the sales and other possible information gathered by the cash register in a day of work. However, these may be subject to change or addition as we move further with this project.
  >Design Patterns:
  > *One Design Pattern we will be using is the Strategy Behavorial Pattern as it allows a family of Algorithms to become interchangeable. This will be utilized in our implementation of Items within a store as each Item while share similarities with each other but also have many different differences between each other such as departments so we want the client using it to be able to apply/scan multiple Items to the cash register that all have different behaviour in some way. While, we also want the cash register to be able to be utilized not just for Stores but for restaurants or any other service that requires a monetary customer interaction.
  > *Another Design Pattern we will be using is the Abstract Factory pattern as it provides an interface creating large groups of similar objects. We want to use that pattern as it will allow our cash registar to be able to handle a myraid of products that may all have different features or requirements for purchase such as Alcohol. This will also allow us to have a large variety of products that are semi independent from each other, so if we need to change one product, the rest are not affected.
  > *Another pattern we will be using is the Iterator pattern as it will allow us to access our data sequentially without any risk of exposure. Since we will be collected a large amount of Data in terms of products and sales we will need a way to traverse through that data safely and efficiently which is what an Iterator will allow us to do. Iterator will additionally allow us to protect our traversal of the data we collect without the necessary exposure to the inner representation of our code guaranteeing that the cash register remains operable with less error. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
