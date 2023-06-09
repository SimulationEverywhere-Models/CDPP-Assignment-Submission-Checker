/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "AssignmentType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: AssignmentType
* Description: constructor
********************************************************************/
AssignmentType::AssignmentType( const string &name )
: Atomic( name )
,submit(addInputPort( "submit" ))
,details(addOutputPort( "details" ))
,assgn_time(0,0,5,0)
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
// ,out(addOutputPort( "out" ))
// , in(addInputPort( "in" ))
{
	string time( MainSimulator::Instance().getParameter( description(), "assgn_time" ) ) ;

		if( time != "" )
			assgn_time = time ;
	// TODO: add initialization code here. (reading parameters, initializing private vars, etc)
	// Code templates for reading parameters:
	// read string parameter:
	// 		stringVar = MainSimulator::Instance().getParameter( description(), "paramName" );
	// read int parameter:
	// 		intVar = str2Int( MainSimulator::Instance().getParameter( description(), "initial" ) );
	// read time parameter:
	//		timeVar = string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;
	// read distribution parameters:
	//		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );
	//		MASSERT( dist ) ;
	//		for ( register int i = 0; i < dist->varCount(); i++ )
	//		{
	//			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar( i ) ) ) ;
	//			dist->setVar( i, str2Value( parameter ) ) ;
	//		}
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &AssignmentType::initFunction()
{
	// [(!) Initialize common variables]
			//this->elapsed = Time::Zero;
 			//this->timeLeft = Time::Inf;
 	// this->sigma = Time::Inf; // stays in active state until an external event occurs;
 			//this->sigma = Time::Zero; // force an internal transition in t=0;

 	// TODO: add init code here. (setting first state, etc)
 	
 	// set next transition
 			//holdIn( active, this->sigma  ) ;
	this-> passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &AssignmentType::externalFunction( const ExternalMessage &msg )
{
	//[(!) update common variables]	
			//this->sigma = nextChange();
			//this->elapsed = msg.time()-lastChange();
 			//this->timeLeft = this->sigma - this->elapsed;
	
	//TODO: implement the external function here.
 	// Remember you can use the msg object (mgs.port(), msg.value()) and you should set the next TA (you might use the holdIn method).
 	// EJ:
 	// if( msg.port() == in )
	//{
	//	// Do something
	//	holdIn( active, this->timeLeft );
	// }
	if(msg.port() == submit) {
		assgn_var = msg.value() ;
		holdIn( active, assgn_time );
	}
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &AssignmentType::internalFunction( const InternalMessage & )
{
	//TODO: implement the internal function here


			//this->sigma = Time::Inf; // stays in passive state until an external event occurs;
			//holdIn( passive, this->sigma  );
	this-> passivate();
	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &AssignmentType::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	sendOutput( msg.time(), details, assgn_var) ;
	return *this;

}

AssignmentType::~AssignmentType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
