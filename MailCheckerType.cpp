/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "MailCheckerType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: MailCheckerType
* Description: constructor
********************************************************************/
MailCheckerType::MailCheckerType( const string &name )
: Atomic( name )
,details(addInputPort( "details" ))
,ml_out (addOutputPort( "ml_out" ))
,ml_time(0,0,5,0)
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
// ,out(addOutputPort( "out" ))
// , in(addInputPort( "in" ))
{
	string time( MainSimulator::Instance().getParameter( description(), "ml_time" ) ) ;

			if( time != "" )
				ml_time = time ;
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
Model &MailCheckerType::initFunction()
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
Model &MailCheckerType::externalFunction( const ExternalMessage &msg )
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
	if(msg.port() == details) {
			local_var = msg.value();
			mail_var = local_var%10 ;
			holdIn( active, ml_time );
	}
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &MailCheckerType::internalFunction( const InternalMessage & )
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
Model &MailCheckerType::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	sendOutput( msg.time(), ml_out, mail_var) ;
	return *this;

}

MailCheckerType::~MailCheckerType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
