/*******************************************************************
*
*  Auto Generated File
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  This registration file is used to describe the atomic models that can be used to compose coupled models.
*
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "queue.h"      // class Queue
#include "generat.h"    // class Generator
#include "cpu.h"        // class CPU
#include "transduc.h"   // class Transducer
#include "trafico.h"    // class Trafico
//#include "ggad.h"       // DEVS-Graphs interpreter
#include "TimeCheckerType.h"        // class TimeCheckerType
#include "PlagiarismCheckerType.h"	// class PlagiarismCheckerType
#include "MailCheckerType.h"	// class MailCheckerType
#include "AssignmentType.h"	// class AssignmentType
#include "ObserverType.h"	// class ObserverType

void MainSimulator::registerNewAtomics()
{
	// Register Built-in models
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
	//SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Ggad>() , "Ggad" ) ; // DEVS-GRAPHS interpreter

	// Register custom models
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TimeCheckerType>(), "TimeCheckerType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<PlagiarismCheckerType>() , "PlagiarismCheckerType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MailCheckerType>() , "MailCheckerType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AssignmentType>() , "AssignmentType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ObserverType>() , "ObserverType" ) ;

}
