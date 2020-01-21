import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MoradoresComponent } from './moradores.component';

describe('MoradoresComponent', () => {
  let component: MoradoresComponent;
  let fixture: ComponentFixture<MoradoresComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MoradoresComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MoradoresComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
