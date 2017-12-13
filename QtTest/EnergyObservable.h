/*
* EnergyObservable.h
*
*  Created on: 20.11.2012
*      
*/

#ifndef ENERGYOBSERVABLE_H_
#define ENERGYOBSERVABLE_H_

#include <memory>

#include <qsharedpointer.h>

#include "Observable.h"

class Hamiltonian;

/// Energy & heat capacity

class EnergyObservable : public Observable
{
public:
	EnergyObservable(int numberMeasurements, QSharedPointer<Hamiltonian> hamilton,	int numberAtoms);
	virtual ~EnergyObservable();
	virtual std::string get_steps_header(void);
	virtual std::string get_mean_header(void);
	virtual void take_value(void);
	virtual std::string get_step_value(int index);
	virtual std::string get_mean_value(double temperature);
	virtual void clear_storage();

protected:
	QSharedPointer<Hamiltonian> _hamilton; ///< Hamiltonian for energy calculation
	int _numberEnergies; ///< number of energy objects in Hamiltonian
	int _numberAtoms; ///< number of lattice sites

	double** _singleEnergies; ///< storage room for measurement values resolved to energy objects
};

#endif /* ENERGYOBSERVABLE_H_ */
