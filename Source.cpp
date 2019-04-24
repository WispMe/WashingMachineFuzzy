#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

class Fuzzy {
	float WLight, WMed, WHeavy;
	float FThin, FMed, FThick;
	float DLow, DMed, DHigh;
	float RQuick[100], RMed[100], RLong[100];
	float Quick, Moderate, Long;
	float crispOutput;


public:
	void Weight(float a) {
		if (a <= 4)
		{
			WLight = 1;
		}
		else {
			if ((a > 4) && (a < 5)) {
				WLight = (float)(5 - a) / 1;
			}
			else WLight = 0;
		}
		if ((a <= 4) || (a >= 10)) {
			WMed = 0;
		}
		else {
			if ((a > 4) && (a < 5)) {
				WMed = (float)(a - 4) / 1;
			}
			else {
				if ((a > 7) && (a < 10)) {
					WMed = (float)(10 - a) / 3;
				}
				else WMed = 1;
			}
		}
		if (a >= 10) {
			WHeavy = 1;
		}
		else {
			if ((a < 10) && (a > 7)) {
				WHeavy = (float)(a - 7) / 3;
			}
			else WHeavy = 0;
		}
	}

	void Fabric(float a) {
		if (a <= 135)
		{
			FThin = 1;
		}
		else {
			if ((a > 135) && (a < 200)) {
				FThin = (float)(200 - a) / 65;
			}
			else FThin = 0;
		}
		if ((a <= 135) || (a >= 340)) {
			FMed = 0;
		}
		else {
			if ((a > 135) && (a < 200)) {
				FMed = (float)(a - 135) / 65;
			}
			else {
				if ((a > 270) && (a < 340)) {
					FMed = (float)(340 - a) / 70;
				}
				else FMed = 1;
			}
		}
		if (a >= 340) {
			FThick = 1;
		}
		else {
			if ((a < 340) && (a > 270)) {
				FThick = (float)(a - 270) / 70;
			}
			else FThick = 0;
		}
	}

	void Detergent(float a) {
		if (a <= 1)
		{
			DLow = 1;
		}
		else {
			if ((a > 1) && (a < 2)) {
				DLow = (float)(2 - a) / 1;
			}
			else DLow = 0;
		}
		if ((a <= 1) || (a >= 4)) {
			DMed = 0;
		}
		else {
			if ((a > 1) && (a < 2)) {
				DMed = (float)(a - 1) / 1;
			}
			else {
				if ((a > 3) && (a < 4)) {
					DMed = (float)(4 - a) / 1;
				}
				else DMed = 1;
			}
		}
		if (a >= 4) {
			DHigh = 1;
		}
		else {
			if ((a < 4) && (a > 3)) {
				DHigh = (float)(a - 3) / 1;
			}
			else DHigh = 0;
		}
	}

	void tampilkan() {
		cout << "WLight: " << WLight;
		cout << "\nWMed: " << WMed;
		cout << "\nWHeavy: " << WHeavy;
		cout << "\nFThin: " << FThin;
		cout << "\nFMed: " << FMed;
		cout << "\nFThick: " << FThick;
		cout << "\nDLow: " << DLow;
		cout << "\nDMed: " << DMed;
		cout << "\nDHigh: " << DHigh;
	}

	float min(float x, float y, float z) {
		if ((x < y) || (x < z)) {
			return x;
		}
		else if ((y < x ) && (y < z)) {
			return y;
		}
		else {
			return z;
		}
	}


	float max_array(float x[], int n) {
		float max = 0;
		for (int i = 0; i < n; i++) {
			if (x[i] > max) {
				max = x[i];
			}
		}
		return max;
	}

	void rules() {
		int i = 0, j = 0, k = 0, l = 0;

		//Rules 1
		if (WLight != 0 && FThin != 0 && DLow !=0) {
			RQuick[i] = min(WLight, FThin, DLow);
			cout<<"=====================================================\n";
			cout<<"|Rules 1 --> Nilai Keanggotaan Rinse Quick " << RQuick[i] << "\n";
			cout<<"=====================================================\n";
			i++;
		}

		//Rules 2
		if (WLight != 0 && FThin != 0 && DMed != 0) {
			RQuick[i] = min(WLight, FThin, DMed);
			cout << "=====================================================\n";
			cout << "|Rules 2 --> Nilai Keanggotaan Rinse Quick " << RQuick[i] << "\n";
			cout << "=====================================================\n";
			i++;
		}
		
		//Rules 3
		if (WLight != 0 && FThin != 0 && DHigh != 0) {
			RQuick[i] = min(WLight, FThin, DHigh);
			cout << "=====================================================\n";
			cout << "|Rules 3 --> Nilai Keanggotaan Rinse Quick " << RQuick[i] << "\n";
			cout << "=====================================================\n";
			i++;
		}

		//Rules 4
		if (WLight != 0 && FMed != 0 && DLow != 0) {
			RQuick[i] = min(WLight, FMed, DLow);
			cout << "=====================================================\n";
			cout << "|Rules 4 --> Nilai Keanggotaan Rinse Quick " << RQuick[i] << "\n";
			cout << "=====================================================\n";
			i++;
		}

		//Rules 5
		if (WLight != 0 && FMed != 0 && DMed != 0) {
			RQuick[i] = min(WLight, FMed, DMed);
			cout << "=====================================================\n";
			cout << "|Rules 5 --> Nilai Keanggotaan Rinse Quick " << RQuick[i] << "\n";
			cout << "=====================================================\n";
			i++;
		}

		//Rules 6
		if (WLight != 0 && FMed != 0 && DHigh != 0) {
			RMed[j] = min(WLight, FMed, DHigh);
			cout << "=====================================================\n";
			cout << "|Rules 6 --> Nilai Keanggotaan Moderate Quick " << RMed[j] << "\n";
			cout << "=====================================================\n";
			j++;
		}

		//Rules 7
		if (WLight != 0 && FThick != 0 && DLow != 0) {
			RQuick[i] = min(WLight, FThick, DLow);
			cout << "=====================================================\n";
			cout << "|Rules 7 --> Nilai Keanggotaan Rinse Quick " << RQuick[i] << "\n";
			cout << "=====================================================\n";
			i++;
		}

		//Rules 8
		if (WLight != 0 && FThick != 0 && DMed != 0) {
			RQuick[i] = min(WLight, FThick, DMed);
			cout << "=====================================================\n";
			cout << "|Rules 8 --> Nilai Keanggotaan Rinse Quick " << RQuick[i]<<"\n";
			cout << "=====================================================\n";
			i++;
		}

		//Rules 9
		if (WLight != 0 && FThick != 0 && DHigh != 0) {
			RMed[j] = min(WLight, FThick, DHigh);
			cout << "=====================================================\n";
			cout << "|Rules 9 --> Nilai Keanggotaan Rinse Moderate " << RMed[j]<<"\n";
			cout << "=====================================================\n";
			j++;
		}

		//Rules 10
		if (WMed != 0 && FThin != 0 && DLow != 0) {
			RQuick[i] = min(WMed, FThin, DLow);
			cout << "=====================================================\n";
			cout << "|Rules 10 --> Nilai Keanggotaan Rinse Quick " << RQuick[i] << "\n";
			cout << "=====================================================\n";
			i++;
		}

		//Rules 11
		if (WMed != 0 && FThin != 0 && DMed != 0) {
			RMed[j] = min(WMed, FThin, DMed);
			cout << "=====================================================\n";
			cout << "|Rules 11 --> Nilai Keanggotaan Rinse Moderate " << RMed[j] << "\n";
			cout << "=====================================================\n";
			j++;
		}

		//Rules 12
		if (WMed != 0 && FThin != 0 && DHigh != 0) {
			RMed[j] = min(WMed, FThin, DHigh);
			cout << "=====================================================\n";
			cout << "|Rules 12 --> Nilai Keanggotaan Rinse Moderate " << RMed[j] << "\n";
			cout << "=====================================================\n";
			j++;
		}

		//Rules 13
		if (WMed != 0 && FMed != 0 && DLow != 0) {
			RQuick[i] = min(WMed, FMed, DLow);
			cout << "=====================================================\n";
			cout << "|Rules 13 --> Nilai Keanggotaan Rinse Quick " << RQuick[i] << "\n";
			cout << "=====================================================\n";
			i++;
		}

		//Rules 14
		if (WMed != 0 && FMed != 0 && DMed != 0) {
			RMed[j] = min(WMed, FMed, DMed);
			cout << "=====================================================\n";
			cout << "|Rules 14 --> Nilai Keanggotaan Rinse Moderate " << RMed[j] << "\n";
			cout << "=====================================================\n";
			j++;
		}

		//Rules 15
		if (WMed != 0 && FMed != 0 && DHigh != 0) {
			RLong[k] = min(WMed, FMed, DHigh);
			cout << "=====================================================\n";
			cout << "|Rules 15 --> Nilai Keanggotaan Rinse Long " << RLong[k] << "\n";
			cout << "=====================================================\n";
			k++;
		}

		//Rules 16
		if (WMed != 0 && FThick != 0 && DLow != 0) {
			RMed[j] = min(WMed, FThick, DLow);
			cout << "=====================================================\n";
			cout << "|Rules 16 --> Nilai Keanggotaan Rinse Moderate " << RMed[j] << "\n";
			cout << "=====================================================\n";
			j++;
		}

		//Rules 17
		if (WMed != 0 && FThick != 0 && DMed != 0) {
			RLong[k] = min(WMed, FThick, DMed);
			cout << "=====================================================\n";
			cout << "|Rules 17 --> Nilai Keanggotaan Rinse Long " << RLong[k] << "\n";
			cout << "=====================================================\n";
			k++;
		}

		//Rules 18
		if (WMed != 0 && FThick != 0 && DHigh != 0) {
			RLong[k] = min(WMed, FThick, DHigh);
			cout << "=====================================================\n";
			cout << "|Rules 18 --> Nilai Keanggotaan Rinse Long " << RLong[k] << "\n";
			cout << "=====================================================\n";
			k++;
		}

		//Rules 19
		if (WHeavy != 0 && FThin != 0 && DLow != 0) {
			RQuick[i] = min(WHeavy, FThin, DLow);
			cout << "=====================================================\n";
			cout << "|Rules 19 --> Nilai Keanggotaan Rinse Quick " << RQuick[i] << "\n";
			cout << "=====================================================\n";
			i++;
		}

		//Rules 20
		if (WHeavy != 0 && FThin != 0 && DMed != 0) {
			RMed[j] = min(WHeavy, FThin, DMed);
			cout << "=====================================================\n";
			cout << "|Rules 20 --> Nilai Keanggotaan Rinse Moderate " << RMed[j] << "\n";
			cout << "=====================================================\n";
			j++;
		}

		//Rules 21
		if (WHeavy != 0 && FThin != 0 && DHigh != 0) {
			RLong[k] = min(WHeavy, FThin, DHigh);
			cout << "=====================================================\n";
			cout << "|Rules 21 --> Nilai Keanggotaan Rinse Quick " << RLong[k] << "\n";
			cout << "=====================================================\n";
			k++;
		}

		//Rules 22
		if (WHeavy != 0 && FMed != 0 && DLow != 0) {
			RMed[j] = min(WHeavy, FMed, DLow);
			cout << "=====================================================\n";
			cout << "|Rules 22 --> Nilai Keanggotaan Rinse Moderate " << RMed[j] << "\n";
			cout << "=====================================================\n";
			j++;
		}

		//Rules 23
		if (WHeavy != 0 && FMed != 0 && DMed != 0) {
			RLong[k] = min(WHeavy, FMed, DMed);
			cout << "=====================================================\n";
			cout << "|Rules 23 --> Nilai Keanggotaan Rinse Long " << RLong[k] << "\n";
			cout << "=====================================================\n";
			k++;
		}

		//Rules 24
		if (WHeavy != 0 && FMed != 0 && DHigh != 0) {
			RLong[k] = min(WHeavy, FMed, DHigh);
			cout << "=====================================================\n";
			cout << "|Rules 24 --> Nilai Keanggotaan Rinse Long " << RLong[k] << "\n";
			cout << "=====================================================\n";
			k++;
		}

		//Rules 25
		if (WHeavy != 0 && FThick != 0 && DLow != 0) {
			RMed[j] = min(WHeavy, FThick, DLow);
			cout << "=====================================================\n";
			cout << "|Rules 25 --> Nilai Keanggotaan Rinse  Moderate " << RMed[j] << "\n";
			cout << "=====================================================\n";
			j++;
		}

		//Rules 26
		if (WHeavy != 0 && FThick != 0 && DMed != 0) {
			RLong[k] = min(WHeavy, FThick, DMed);
			cout << "=====================================================\n";
			cout << "|Rules 26 --> Nilai Keanggotaan Rinse Long " << RLong[k] << "\n";
			cout << "=====================================================\n";
			k++;
		}

		//Rules 27
		if (WHeavy != 0 && FThick != 0 && DHigh != 0) {
			RLong[k] = min(WHeavy, FThick, DHigh);
			cout << "=====================================================\n";
			cout << "|Rules 27 --> Nilai Keanggotaan Rinse Quick " << RLong[k] << "\n";
			cout << "=====================================================\n";
			k++;
		}

		if (i == 0) {
			Quick = 0;
		}

		else {
			Quick = max_array(RQuick, i);
		}

		if (j == 0) {
			Moderate = 0;
		}

		else {
			Moderate = max_array(RMed, j);
		}

		if (k == 0) {
			Long = 0;
		}

		else {
			Long = max_array(RLong, k);
		}
		
		//Hasil Akhir Inferensi
		cout << "\n=====================================\n";
		cout << "|       Hasil Akhir Inferensi       |\n";
		cout << "|  Nilai Keanggotaan Quick Rinse = " << Quick << "\n";
		cout << "|  Nilai Keanggotaan Moderate Rinse = " << Moderate << "\n";
		cout << "|  Nilai Keanggotaan Long Rinse = " << Long << "\n";
		cout << "=====================================\n";
	}

	float NKQuick(float x) {
		if (x <= 4) return 1;
		else {
			if ((x < 8) && (x > 4)) return (float)((8 - x) / 4);
			else return 0;
		}
	}

	float NKModerate(float x) {
		if (x = 8) return 1;
		else {
			if ((x > 4) && (x < 8)) return (float)((x - 4) / 4);
			else {
				if ((x > 8) && (x < 12)) return (float)((12 - x) / 4);
				else return 0;
			}
		}
	}


	float NKLong(float x) {
		if (x <= 8) return 0;
		else {
			if ((x > 8) && (x < 12)) return (float)((x - 8) / 4);
			else return 1;
		}
	}

	void defuzz_centroid(float sampel) {
		float min_output = 0, max_output = 15;
		float x = 0, t = (max_output - min_output) / sampel;
		float pengali[100];
		float valQuick, valModerate, valLong;
		float crisp_val = 0;
		float sumX = 0;
		int i;
		//string result ="";

		for (i = 0; i < sampel; i++) {
			x = x + t;
			valQuick = NKQuick(x);
			valModerate = NKModerate(x);
			valLong = NKLong(x);

			if (valQuick > Quick)
				valQuick = Quick;

			if (valModerate > Moderate)
				valModerate = Moderate;

			if (valLong > Long)
				valLong = Long;


			if (valQuick >= valModerate && valQuick >= valLong) {
				pengali[i] = valQuick;
			}
			else if (valModerate >= valQuick && valModerate >= valLong) {
				pengali[i] = valModerate;
			}
			else {
				pengali[i] = valLong;

			}


			crisp_val = crisp_val + (x*pengali[i]);
			sumX = sumX + pengali[i];
		}
		cout << "==================================\n";
		cout << "|       crisp_val = " << crisp_val << "        |\n";
		cout << "|       sumX      = " << sumX << "         |\n";
		crispOutput = crisp_val / sumX;
		cout << "|       ncrips    = " << crispOutput << "        |\n";
		cout << "==================================\n";
	}


};

int main() {
	float weight, fabric, detergent, sampel;
	Fuzzy panggil;

	cout << "Masukkan nilai berat: ";
	cin >> weight;
	cout << "Masukkan nilai fabric: ";
	cin >> fabric;
	cout << "Masukkan nilai detergent: ";
	cin >> detergent;
	panggil.Weight(weight);
	panggil.Fabric(fabric);
	panggil.Detergent(detergent);
	panggil.tampilkan();
	cout << "\n-Rules yang dipakai dalam Inferensi-\n";
	panggil.rules();
	cout << "\nMasukkan jumlah sampel pada Centroid : ";
	cin >> sampel;
	system("cls");
	panggil.defuzz_centroid(sampel);
	cout << "\n";
	system("pause");

	return 0;
}