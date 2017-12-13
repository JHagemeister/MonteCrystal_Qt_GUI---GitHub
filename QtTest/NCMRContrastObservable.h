#ifndef NCMRCONTRASTOBSERVABLE_H
#define NCMRCONTRASTOBSERVABLE_H

#include "typedefs.h"

#include "Observable.h"

/// Non collinear magneto resistance contrast
/** NCMR contrast as observed by tip of scanning tunneling microscope
*/
class NCMRContrastObservable: public Observable
{
public:
	NCMRContrastObservable(int numberMeasurements, Threedim* spinArray, int numberAtoms, int* neighborArray, 
		int nbors);
	~NCMRContrastObservable();
	virtual std::string get_steps_header(void);
	virtual std::string get_mean_header(void);
	virtual void take_value(void);
	virtual std::string get_step_value(int index);
	virtual std::string get_mean_value(double temperature);
	virtual void clear_storage();

private:

	double ncmr_contrast_value(int position);

	Threedim* _spinArray;
	int _numberAtoms;
	int* _neighborArray;
	int _nbors;

	double** _ncmrValues;
};

#endif //NCMRCONTRASTOBSERVABLE_H