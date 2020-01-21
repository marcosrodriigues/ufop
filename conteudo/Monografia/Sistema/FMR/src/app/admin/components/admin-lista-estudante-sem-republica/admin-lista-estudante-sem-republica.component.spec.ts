import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AdminListaEstudanteSemRepublicaComponent } from './admin-lista-estudante-sem-republica.component';

describe('AdminListaEstudanteSemRepublicaComponent', () => {
  let component: AdminListaEstudanteSemRepublicaComponent;
  let fixture: ComponentFixture<AdminListaEstudanteSemRepublicaComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AdminListaEstudanteSemRepublicaComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AdminListaEstudanteSemRepublicaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
