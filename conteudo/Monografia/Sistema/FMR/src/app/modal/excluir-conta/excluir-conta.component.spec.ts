import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ExcluirContaComponent } from './excluir-conta.component';

describe('ExcluirContaComponent', () => {
  let component: ExcluirContaComponent;
  let fixture: ComponentFixture<ExcluirContaComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ExcluirContaComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ExcluirContaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
