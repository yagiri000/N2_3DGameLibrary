#include <math.h>

#include "EulerAngles.h"
#include "Quaternion.h"
#include "MathUtil.h"
#include "Matrix4x3.h"
#include "RotationMatrix.h"


const EulerAngles kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);

void EulerAngles::canonize() {
	// pitch��-Pi~Pi�Ƀ��b�v����
	pitch = wrapPi(pitch);

	// 
	if (pitch < -kPiOver2) {
		pitch = -kPi - pitch;
		heading += kPi;
		bank += kPi;
	}else if(pitch > kPiOver2){
		pitch = kPi - pitch;
		heading += kPi;
		bank += kPi;
	}

	// �W���o�����b�N���ɂ��邩�m�F
	if (fabs(pitch) > kPiOver2 - 1e-4) {
		heading += bank;
		bank = 0.0f;
	}
	else {
		bank = wrapPi(bank);
	}

	// �w�f�B���O�𐳏��͈͂Ƀ��b�v����
	heading = wrapPi(heading);
}


