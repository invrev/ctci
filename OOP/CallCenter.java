

//Call center has employees
//Employee are of 3 types MGR,RESP,DIRECT
//Functionality is to give service to caller
//dispatchCall from RESP to DIRECT untill no free employee available
//Caller needs to put on hold if no one is available


//Util class
class Name {
    string firstName;
    string lastName;
    string middleName;
    string mailId;
    string phoneNumber;
}

class CallCenter {
    //List<Mgr> mgrList;
    //List<Resp> respList;
    //List<Direct> directList;
    //List< List <Employee> > allEmployee;
    private Map< Rank,List<Employee> > allEmployee;
    private queue<Call> callq;
    
    void dispatchCall (Call c) {
        //Iterate over respondant list
        //List<Employee> e1 = allEmployee.get(Rank.RESP);
        //List<Employee> e2 = allEmployee.get(Rank.MGR);
        bool isCallProcessed = false;
        for  (Rank r:Rank.values() ) {
            List<Employee> e1 = allEmployee.get(Rank.r);
            for (Employee e:e1) {
                if (r.isFree () == true)  {
                    //process the call
                    isCallProcessed  = true;
                    break;
                }
            }
        }
        if (isCallProcessed == true) {
            callq.push(c);     
        }

        //for (Resp r:respList) {
        //    if (r.isFree () == true )  {
        //        //process the call
        //    }
        //}
    }


}


class enum State {
    Free(0),Busy(1),onLeave(2),onSabtical(3)
}

interface EmployeeAccessable {
    void addEmployee(Employee e);
    Employee RemoveEmployee();
    Employee promoteEmployee();
}

class Employee {
    Name name;
    Rank rank;
    Position p;
    State s;
    //functionality
    void pickUpAndAnswercall();
    State isFree();
}

class Call {
    Name name;
    string timeStamp;
}

class enum Rank {
    DIRECT(1),MGR(2),RESP(3)
}

class MGR extends Employee{
    Rank r;
    Direct (Rank gr) {
       this.r = gr;
    }
}

class Direct extends Employee implements EmployeeAccessable {
    Rank r;
    Direct (Rank gr) {
       this.r = gr;
    }
}

class Resp extends Employee{
    Rank r;
    Direct (Rank gr) {
       this.r = gr;
    }
}

