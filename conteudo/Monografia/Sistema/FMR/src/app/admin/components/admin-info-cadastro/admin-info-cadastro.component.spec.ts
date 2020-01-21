import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AdminInfoCadastroComponent } from './admin-info-cadastro.component';

describe('AdminInfoCadastroComponent', () => {
  let component: AdminInfoCadastroComponent;
  let fixture: ComponentFixture<AdminInfoCadastroComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AdminInfoCadastroComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AdminInfoCadastroComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
