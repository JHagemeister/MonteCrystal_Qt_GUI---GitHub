/*
* DMInteractionDefect.h
*
*/

#ifndef DMINTERACTIONDEFECT_H_
#define DMINTERACTIONDEFECT_H_

#include "Energy.h"
#include <unordered_map>
#include <vector>

class Lattice;

/// Dzyaloshinskii-Moriya interaction

class DMInteractionDefect : public Energy
{
public:
	DMInteractionDefect(Threedim* spinArray, Threedim direction,
		const std::unordered_map<int, double> &defects, DMType dmType,
		Lattice* lattice, int order);
	virtual ~DMInteractionDefect();

	virtual double single_energy(const int &position) const;
	virtual Threedim effective_field(const int &position) const;

protected:
	void set_DM_vectors(const std::unordered_map<int, double> &defects, Lattice* lattice); ///< setup DM vectors

	Threedim _direction; ///< used to set up DM vectors
	int _nbors; ///< number of neighbors
	int* _neighborArray; ///< indexes of neighbors
	std::unordered_map<int, std::vector<Threedim>> _dmVectors;
	DMType _dmType; ///< 1 for chiral 0 for Neel type interaction
	int _order; ///< 1 nearest-neighbor, 2 next-nearest...
};

#endif /* DMINTERACTION_H_ */

