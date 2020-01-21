import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AdminCadaRepublicaListaComponent } from './admin-cada-republica-lista.component';

describe('AdminCadaRepublicaListaComponent', () => {
  let component: AdminCadaRepublicaListaComponent;
  let fixture: ComponentFixture<AdminCadaRepublicaListaComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AdminCadaRepublicaListaComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AdminCadaRepublicaListaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
