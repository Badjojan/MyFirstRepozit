#include<iostream>
#include"Weapon.h"
using namespace std;

int main() {

	AbstractWeapon** weapons = new AbstractWeapon*[3];
	Point3D GunPt = { 7,7,7 };
	Point3D shotGunPt = { 10,10,10 };
	Point3D automaticPt = { 20,20,20 };
	Vector3D GunLc = { 40,40,40 };
	Vector3D shotGunLc = { 80,80,80 };
	Vector3D automaticLc = { 120,120,120 };


	weapons[0] = new Shotgun();
	weapons[1] = new AutomaticWeapon();
	weapons[2] = new Gun();

	weapons[0]->SetLocation(shotGunPt);
	weapons[1]->SetLocation(automaticPt);
	weapons[2]->SetLocation(GunPt);

	weapons[0]->SetDirection(shotGunLc);
	weapons[1]->SetDirection(automaticLc);
	weapons[2]->SetDirection(GunLc);

	for (int i = 0;i < 3; i++) {
		AbstractBullet* bullet = weapons[i]->Shoot();
		bullet->HitTarget(NULL);
		delete bullet;
	}

	
	for (int i = 0;i < 3; i++) {
		delete weapons[i];
	}

	delete[]weapons;

	return 0;
} 