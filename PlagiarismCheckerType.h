/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __PlagiarismCheckerType_H
#define __PlagiarismCheckerType_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class PlagiarismCheckerType: public Atomic
{
public:
	PlagiarismCheckerType( const string &name = "PlagiarismCheckerType" ) ;	 // Default constructor
	~PlagiarismCheckerType();					// Destructor
	virtual string className() const
		{return "PlagiarismCheckerType";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &details;
	Port &pc_out;

	Time pc_time;
	int p_local;
	int plag_var;
	int pc_var;
	// [(!) TODO: declare ports, distributions and other private varibles here]
	/***********      Example declarations   **********************************/
	// const Port &in;	// this is an input port named 'in'
	// Port &out ;   	// this is an output port named 'out'
	// Distribution *dist ;
	// Distribution &distribution()	{ return *dist; }
	/**************************************************************************/

	// [(!) declare common variables]
	// Lifetime programmed since the last state transition to the next planned internal transition.
	Time sigma;
	
	// Time elapsed since the last state transition until now
	Time elapsed;
	
	// Time remaining to complete the last programmed Lifetime
	Time timeLeft;	
};	// class PlagiarismCheckerType


#endif   //__PlagiarismCheckerType_H 
