/*
* DMInteraction.h
*      
*/

#ifndef DMINTERACTION_H_
#define DMINTERACTION_H_

#include "Energy.h"

class Lattice;

/// Dzyaloshinskii-Moriya interaction

class DMInteraction : public Energy
{
public:
	DMInteraction(Threedim* spinArray, double energyParameter, Threedim direction, DMType dmType, 
		Lattice* lattice, int order);
	virtual ~DMInteraction();

	virtual double single_energy(int position);
	virtual double interaction_energy_between_two_spins(int position1, int position2);
	
	virtual Threedim effective_field(int position);

	int get_nbors(void);
	int* get_neighbor_array(void);
	Threedim* get_dm_vectors(void);

protected:
	void set_DM_vectors(Lattice* lattice); ///< setup DM vectors

	Threedim _direction; ///< used to set up DM vectors
	int _nbors; ///< number of neighbors
	int* _neighborArray; ///< indexes of neighbors
	Threedim* _DMVectors; ///< DM vectors
	DMType _dmType; ///< 1 for chiral 0 for Neel type interaction
	int _order; ///< 1 nearest-neighbor, 2 next-nearest...
};

#endif /* DMINTERACTION_H_ */
