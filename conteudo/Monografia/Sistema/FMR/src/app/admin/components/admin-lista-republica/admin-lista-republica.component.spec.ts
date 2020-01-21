import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AdminListaRepublicaComponent } from './admin-lista-republica.component';

describe('AdminListaRepublicaComponent', () => {
  let component: AdminListaRepublicaComponent;
  let fixture: ComponentFixture<AdminListaRepublicaComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AdminListaRepublicaComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AdminListaRepublicaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
