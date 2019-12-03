import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { EsqueciMinhaSenhaComponent } from './esqueci-minha-senha.component';

describe('EsqueciMinhaSenhaComponent', () => {
  let component: EsqueciMinhaSenhaComponent;
  let fixture: ComponentFixture<EsqueciMinhaSenhaComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ EsqueciMinhaSenhaComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(EsqueciMinhaSenhaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
