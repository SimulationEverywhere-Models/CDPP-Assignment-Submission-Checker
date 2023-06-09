/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "ObserverType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: ObserverType
* Description: constructor
********************************************************************/
ObserverType::ObserverType( const string &name )
: Atomic( name )
,tc_out(addInputPort( "tc_out" ))
,pc_out(addInputPort( "pc_out" ))
,ml_out(addInputPort( "ml_out" ))
,response(addOutputPort( "response" ))
,response_time(0,0,10,0)
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
// ,out(addOutputPort( "out" ))
// , in(addInputPort( "in" ))
{
	string time( MainSimulator::Instance().getParameter( description(), "response_time" ) ) ;

		   if( time != "" )
				response_time = time ;
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
Model &ObserverType::initFunction()
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
Model &ObserverType::externalFunction( const ExternalMessage &msg )
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
	
	if(msg.port() == tc_out) {
			if(msg.value() == 1)
				t_val = 1;
			else
				t_val = 0;
			holdIn( active, response_time );
		}

		if(msg.port() == pc_out) {
			if(msg.value() == 1)
				p_val = 1;
			else
				p_val = 0;
			holdIn( active, response_time );
		}

		if(msg.port() == ml_out) {
			if(msg.value() == 1)
				m_val = 1;
			else
				m_val = 0;
			holdIn( active, response_time );
		}

		if(t_val == 1 && p_val == 1 && m_val == 1 )
			o_val = 1;
		else
			o_val = 0;

		holdIn( active, response_time );
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &ObserverType::internalFunction( const InternalMessage & )
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
Model &ObserverType::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	sendOutput( msg.time(), response, o_val) ;
	return *this;

}

ObserverType::~ObserverType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
